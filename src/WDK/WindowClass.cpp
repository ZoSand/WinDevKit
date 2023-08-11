#include <WDK/WindowClass.hpp>

#include <WDK/Window.hpp>

namespace WDK
{
	WindowClass::WindowClass(WDK::String _className)
	{
		::ZeroMemory(&m_class, sizeof(::WNDCLASSEX)); //ensure no parasite data

		m_class.cbSize = sizeof(::WNDCLASSEX);
		m_class.lpfnWndProc =  &Window::WndProc;
		m_class.hInstance = ::GetModuleHandle(nullptr);
		m_class.lpszClassName = _className.GetNativeString();
	}

	WindowClass::WindowClass(::WNDCLASSEX _nativeClass)
		: m_class(_nativeClass)
	{
	}

	::WNDCLASSEX WindowClass::GetNativeClass() const
	{
		return m_class;
	}

	::ATOM WindowClass::Register()
	{
		return ::RegisterClassEx(&m_class);
	}

	bool WindowClass::Unregister()
	{
		return ::UnregisterClass(this->m_class.lpszClassName, this->m_class.hInstance) == TRUE;
	}

	bool WindowClass::UnregisterSecure()
	{
		//unregister class if no one uses it
		if (::FindWindowEx(nullptr, nullptr, this->m_class.lpszClassName, nullptr) != nullptr)
		{
			return ::UnregisterClass(this->m_class.lpszClassName, this->m_class.hInstance) == TRUE;
		}
		return false;
	}
}