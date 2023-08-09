#pragma once

#include <windows.h>

//TODO Zo: comment methods; implement missing string methods

namespace WDK
{
	class String
	{
	public:
		String(::LPCTSTR _string);

		::LPTSTR GetNativeString() const;

		int Length();
	private:
		::LPTSTR m_string;
	};
}