#include <WDK/String.hpp>

#include <Shlwapi.h>

namespace WDK
{
	String::String(const ::LPCTSTR _string)
	{
		this->m_string = ::StrDup(_string);
		if (this->m_string != NULL)
		{
			LocalFree(this->m_string);
		}
	}

	::LPTSTR String::GetNativeString() const
	{
		return m_string;
	}

	int String::Length()
	{
		return lstrlen(this->m_string);
	}
}