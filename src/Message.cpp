#include <WDK/Message.hpp>

namespace WDK
{
	Message::Message()
	{
		this->m_message = ::MSG();
	}

	Message::Message(::MSG _message)
	{
		this->m_message = ::MSG(_message);
	}
	
	Message::Message(::HWND _window, ::UINT _message, ::WPARAM _wParam, ::LPARAM _lParam)
	{
		this->m_message.hwnd = _window;
		this->m_message.message = _message;
		this->m_message.wParam = _wParam;
		this->m_message.lParam = _lParam;
	}

	::MSG Message::GetNativeMessage() const
	{
		return this->m_message;
	}
	
	bool Message::Post(Window _window, ::UINT _message, ::WPARAM _wParam, ::LPARAM _lParam)
	{
		return ::PostMessage(_window.GetNativeHandle(), _message, _wParam, _lParam);
	}

	bool Message::Peek(Window _wnd, unsigned _min, unsigned _max, Removability _remove)
	{
		return ::PeekMessage(&this->m_message, _wnd.GetNativeHandle(), _min, _max, _remove);
	}

	bool Message::Get(Window _wnd, unsigned _min, unsigned _max)
	{
		return ::GetMessage(&this->m_message, _wnd.GetNativeHandle(), _min, _max);
	}


	bool Message::Translate()
	{
		return ::TranslateMessage(&this->m_message);
	}


	bool Message::Dispatch()
	{
		return ::DispatchMessage(&this->m_message);
	}
	bool Message::TranslateAndDispatch()
	{
		return Message::Translate() && Message::Dispatch();
	}
}