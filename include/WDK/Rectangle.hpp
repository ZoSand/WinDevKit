#pragma once

#include <WDK/Window.hpp>

#include <windows.h>

//TODO Zo: document methods

namespace WDK
{

	class Rectangle
	{
	public:
		Rectangle();
		Rectangle(::RECT _rect);
		Rectangle(long _left, long _top, long _right, long _bottom);

		long GetLeft() const;
		long GetTop() const;
		long GetRight() const;
		long GetBottom() const;

		long GetWidth() const;
		long GetHeight() const;

		::LONG GetArea() const;
		
		::RECT GetNativeRect() const;

		Rectangle SetLeft(long _left);
		Rectangle SetTop(long _top);
		Rectangle SetRight(long _right);
		Rectangle SetBottom(long _bottom);

		Rectangle SetWidth(long _width);
		Rectangle SetHeight(long _height);

		Rectangle Adjust(Window::Style _style = Window::Style::OverlappedWindow, bool _isMenu = false);

		static Rectangle FromDimension(long _left, long _top, long _width, long _height);
	private:
		::RECT m_rect;
	};
}