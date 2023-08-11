#pragma once

#include <WDK/String.hpp>

#include <windows.h>

namespace WDK
{
	class WindowClass
	{
	public:
		WindowClass(WDK::String _className);
		WindowClass(::WNDCLASSEX _nativeClass);

		::WNDCLASSEX GetNativeClass() const;

		//TODO Zo: Getters/Setters

		::ATOM Register();

		bool Unregister();

		bool UnregisterSecure();
	private:
		::WNDCLASSEX m_class;
	};
}