#include <WDK/String.hpp>

#include <strsafe.h>

namespace WDK
{
	String::String(const ::LPCTSTR _string)
	{
		int len = ::lstrlen(_string);
		::SIZE_T allocSize = len * sizeof(TCHAR);
		
		this->m_string = static_cast<::LPTSTR>(::LocalAlloc(LPTR, allocSize)); //TODO Zo: check for null

		if (this->m_string == 0)
		{
			throw;
		}

		::StringCchCopy(this->m_string, allocSize, _string); //TODO Zo: check return

		if (this->m_string == NULL)
		{
			::LocalFree(this->m_string);
		}
	}

	String::~String()
	{
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