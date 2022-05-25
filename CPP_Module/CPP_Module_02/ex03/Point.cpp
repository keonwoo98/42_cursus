#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{ }

Point::Point(const Point &pt) : _x(pt._x), _y(pt._y)
{ }

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{ }

Point::Point(const float x, const float y) : _x(x), _y(y)
{ }

Point::~Point(void)
{ }

Point& Point::operator=(const Point &pt)
{
	const_cast<Fixed&>(_x) = pt.get_x();
	const_cast<Fixed&>(_y) = pt.get_y();
	return *this;
}

const Fixed& Point::get_x(void) const
{
	return _x;
}

const Fixed& Point::get_y(void) const
{
	return _y;
}
