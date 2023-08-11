#include <WDK/Window.hpp>

#include <WDK/Definitions.hpp>
#include <WDK/Rectangle.hpp>
#include <WDK/Message.hpp>

#include <cassert>

#include <string>
#include <iostream>

namespace WDK
{
	//----------public----------

	Window::Window()
		: m_handle(nullptr)
	{
	}

	Window::Window(::HWND _handle)
		: m_handle(_handle)
	{
	}

	Window::Window(
		WDK::WindowClass _class,
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
		::WNDCLASSEX nativeClass = _class.GetNativeClass();

		this->m_handle = ::CreateWindowEx(
			exStyle,
			nativeClass.lpszClassName,
			_title.GetNativeString(),
			style,
			_clientArea.GetLeft(),
			_clientArea.GetTop(),
			_clientArea.GetWidth(),
			_clientArea.GetHeight(),
			_parent.m_handle,
			nullptr,
			nativeClass.hInstance,
			nullptr //this
		);

		//TODO Zo: WDK::Utils::GetLastError
		WDK_ASSERT(this->m_handle != nullptr, "Could not create handle");
	}

	Window::~Window()
	{
	}

	::HWND Window::GetNativeHandle() const
	{
		return this->m_handle;
	}

	bool Window::Destroy()
	{
		bool result = ::DestroyWindow(this->m_handle) != FALSE;
		this->m_handle = static_cast<::HWND>(nullptr);
		return result;
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
		return ::IsIconic(this->m_handle) != FALSE;
	}

	bool Window::IsMaximized() const
	{
		return ::IsZoomed(this->m_handle) != FALSE;
	}

	bool Window::IsVisible() const
	{
		return ::IsWindowVisible(this->m_handle) != FALSE;
	}

	bool Window::IsOpen()
	{
		return ::IsWindow(this->m_handle) != FALSE;
	}

	bool Window::IsMenu() const
	{
		return false;
	}

	void Window::Open()
	{
		::ShowWindow(this->m_handle, SW_SHOW);
	}

	void Window::Update()
	{
		/*return*/ 
		::UpdateWindow(m_handle);
	}

	//STATIC METHODS
	::LRESULT CALLBACK Window::WndProc(
		::HWND _hWnd,
		::UINT _uMsg,
		::WPARAM _wParam,
		::LPARAM _lParam
	)
	{
		std::cout << _uMsg << std::endl;

		switch (_uMsg)
		{
		case WM_CLOSE:
			std::cout << "Close" << std::endl;
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

	//----------protected----------

	//----------private----------
}