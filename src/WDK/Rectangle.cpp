#include <WDK/Rectangle.hpp>

namespace WDK
{
	Rectangle::Rectangle()
		: m_rect({ 0, 0, 0, 0 })
	{
	}

	Rectangle::Rectangle(::RECT _rect)
		: m_rect(_rect)
	{
	}

	Rectangle::Rectangle(long _left, long _top, long _right, long _bottom)
		: m_rect({ _left, _top, _right, _bottom })
	{
	}

	long Rectangle::GetLeft() const
	{
		return this->m_rect.left;
	}

	long Rectangle::GetTop() const
	{
		return this->m_rect.top;
	}

	long Rectangle::GetRight() const
	{
		return this->m_rect.right;
	}

	long Rectangle::GetBottom() const
	{
		return this->m_rect.bottom;
	}

	long Rectangle::GetWidth() const
	{
		return this->m_rect.right - this->m_rect.left;
	}

	long Rectangle::GetHeight() const
	{
		return this->m_rect.bottom - this->m_rect.top;
	}
	
	long Rectangle::GetArea() const
	{
		return Rectangle::GetWidth() * Rectangle::GetHeight();
	}


	::RECT Rectangle::GetNativeRect() const
	{
		return this->m_rect;
	}

	Rectangle Rectangle::SetLeft(long _left)
	{
		this->m_rect.left = _left;
		return *this;
	}

	Rectangle Rectangle::SetTop(long _top)
	{
		this->m_rect.top = _top;
		return *this;
	}

	Rectangle Rectangle::SetRight(long _right)
	{
		this->m_rect.right = _right;
		return *this;
	}

	Rectangle Rectangle::SetBottom(long _bottom)
	{
		this->m_rect.bottom = _bottom;
		return *this;
	}

	Rectangle Rectangle::SetWidth(long _width)
	{
		this->m_rect.right = this->m_rect.left + _width;
		return *this;
	}

	Rectangle Rectangle::SetHeight(long _height)
	{
		m_rect.bottom = this->m_rect.top + _height;
		return *this;
	}

	Rectangle Rectangle::Adjust(Window::Style _style, bool _isMenu)
	{
		::AdjustWindowRect(&this->m_rect, _style, _isMenu);
		return *this;
	}

	Rectangle Rectangle::FromDimension(long _left, long _top, long _width, long _height)
	{
		return Rectangle(_left, _top, _left + _width, _top + _height);
	}

}
