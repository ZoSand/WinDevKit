#pragma once

#include <WDK/Window.hpp>

#include <windows.h>

//TODO Zo: comment methods;

namespace WDK
{
	class Message
	{
	public:
		enum Removability
		{
			NoRemove = PM_NOREMOVE,
			Remove = PM_REMOVE,
			NoYield = PM_NOYIELD
		};

		Message();
		Message(::MSG);
		Message(::HWND _window, ::UINT _message, ::WPARAM _wParam, ::LPARAM _lParam);
		
		::MSG GetNativeMessage() const;

		bool Post(Window _window, ::UINT _message, ::WPARAM _wParam, ::LPARAM _lParam);
		
		bool Peek(Window _wnd = Window(), unsigned _min = 0, unsigned _max = 0, Removability _remove = Removability::Remove);

		bool Get(Window _wnd = Window(), unsigned _min = 0, unsigned _max = 0);
		
		bool Translate();
		
		bool Dispatch();

		bool TranslateAndDispatch();

	private:
		::MSG m_message;
	};
}