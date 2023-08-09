#include <WDK/Window.hpp>

#include <WDK/Rectangle.hpp>
#include <WDK/Message.hpp>

#include <cassert>

#define WDK_WINDOW_CLASS_NAME TEXT("WDKWindowClass")

namespace WDK
{
	//----------public----------

	Window::Window()
		: m_handle(nullptr)
		, m_class(0)
	{
	}

	Window::Window(::HWND _handle)
		: m_handle(_handle)
		, m_class(::GetClassWord(_handle, GCW_ATOM))
	{
	}

	Window::Window(
		WDK::String _title,
		WDK::Rectangle _clientArea,
		const Style _style,
		Window _parent
	)
		: m_handle(nullptr)
	{
		::DWORD style = static_cast<::DWORD>(_style & (
			Style::Border
			| Style::Caption
			| Style::Child
			| Style::ChildWindow
			| Style::ClipChildren
			| Style::ClipSiblings
			| Style::Disabled
			| Style::DialogFrame
			| Style::Group
			| Style::HorizontalScroll
			| Style::Iconic
			| Style::Maximized
			| Style::MaximizeBox
			| Style::Minimized
			| Style::MinimizeBox
			| Style::Overlapped
			| Style::OverlappedWindow
			| Style::Popup
			| Style::PopupWindow
			| Style::SizeBox
			| Style::SysMenu
			| Style::TabStop
			| Style::ThickFrame
			| Style::Tiled
			| Style::TiledWindow
			| Style::Visible
			| Style::VerticalScroll
			));

		//TODO Zo: parse _style Extended
		::DWORD exStyle = static_cast<::DWORD>(0);

		::WNDCLASSEX windowClass = { 0 };
		int x = _clientArea.GetLeft();
		int y = _clientArea.GetTop();

		windowClass.cbSize = sizeof(::WNDCLASSEX);
		windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		windowClass.lpfnWndProc = &Window::WndProc;
		windowClass.hInstance = ::GetModuleHandle(nullptr);
		windowClass.hCursor = ::LoadCursor(nullptr, IDC_ARROW);
		windowClass.hbrBackground = reinterpret_cast<::HBRUSH>(COLOR_WINDOW + 1);
		windowClass.lpszClassName = WDK_WINDOW_CLASS_NAME;
		windowClass.hIcon = ::LoadIcon(nullptr, IDI_APPLICATION);
		windowClass.hIconSm = ::LoadIcon(nullptr, IDI_APPLICATION);
		m_class = ::RegisterClassEx(&windowClass);

		_clientArea.Adjust(*this, _style);
		this->m_handle = ::CreateWindowExW(
			exStyle,
			MAKEINTRESOURCE(this->m_class),
			_title.GetNativeString(),
			style,
			x,
			y,
			_clientArea.GetWidth(),
			_clientArea.GetHeight(),
			_parent.m_handle,
			nullptr,
			::GetModuleHandle(nullptr),
			nullptr //this
		);

		//TODO Zo: WDK::Utils::GetLastError
		assert(this->m_handle != nullptr);
	}

	Window::~Window()
	{
		::DestroyWindow(this->m_handle);

		//unregister class if no one uses it
		if (::FindWindowEx(nullptr, nullptr, MAKEINTRESOURCE(this->m_class), nullptr) != nullptr)
		{
			::UnregisterClass(MAKEINTRESOURCE(this->m_class), ::GetModuleHandle(nullptr));
		}

		this->m_class = reinterpret_cast<::ATOM>(nullptr);
		this->m_handle = static_cast<::HWND>(nullptr);
	}

	::HWND Window::GetNativeHandle() const
	{
		return this->m_handle;
	}

	Window Window::SetParent(Window _parent)
	{
		return Window(::SetParent(this->m_handle, _parent.m_handle));
	}

	Window Window::AddChild(Window _child)
	{
		//check null window native handle
		assert(_child.m_handle != nullptr && "WDK::Window::AddChild does not take null windows");

		//set child's parent to this window
		return Window(::SetParent(_child.m_handle, this->m_handle));
	}

	std::vector<Window> Window::GetChildren() const
	{
		std::vector<Window> children;

		//get first child
		::HWND child = ::GetWindow(this->m_handle, GW_CHILD);

		//iterate through all children
		while (child != nullptr)
		{
			children.push_back(Window(child));
			child = ::GetWindow(child, GW_HWNDNEXT);
		}

		return children;
	}

	::DWORD Window::GetNativeStyle() const
	{
		return ::GetWindowLong(this->m_handle, GWL_STYLE);
	}

	::DWORD Window::GetNativeExStyle() const
	{
		return ::GetWindowLong(this->m_handle, GWL_EXSTYLE);
	}

	bool Window::IsMinimized() const
	{
		return ::IsIconic(this->m_handle) == TRUE;
	}

	bool Window::IsMaximized() const
	{
		return ::IsZoomed(this->m_handle) == TRUE;
	}

	bool Window::IsVisible() const
	{
		return ::IsWindowVisible(this->m_handle) == TRUE;
	}

	bool Window::IsOpen()
	{
		return ::IsWindow(this->m_handle) == TRUE;
	}

	bool Window::IsMenu() const
	{
		return false;
	}

	void Window::Open()
	{
		::ShowWindow(this->m_handle, SW_SHOW);
		::UpdateWindow(this->m_handle);
	}

	void Window::Update()
	{
		Message message;
		while (message.Peek())
		{
			message.TranslateAndDispatch();
		}
	}

	//----------protected----------

	//----------private----------

	//STATIC METHODS
	::LRESULT CALLBACK Window::WndProc(
		::HWND _hWnd,
		::UINT _uMsg,
		::WPARAM _wParam,
		::LPARAM _lParam
	)
	{
		switch (_uMsg)
		{
		case WM_CLOSE:
			::DestroyWindow(_hWnd);
			break;
		case WM_DESTROY:
			::PostQuitMessage(0);
			break;
		default:
			return ::DefWindowProc(_hWnd, _uMsg, _wParam, _lParam);
		}
		return 0;
	}
}