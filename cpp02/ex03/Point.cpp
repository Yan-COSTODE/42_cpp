#include "Point.hpp"

Point::~Point()
{
}

Point::Point()
{
	const_cast<Fixed&>(x) = Fixed(0);
	const_cast<Fixed&>(y) = Fixed(0);
}

Point::Point(const float _x, const float _y)
{
	const_cast<Fixed&>(x) = Fixed(_x);
	const_cast<Fixed&>(y) = Fixed(_y);
}

Point::Point(const Point &_other)
{
	const_cast<Fixed&>(x) = Fixed(_other.x);
	const_cast<Fixed&>(y) = Fixed(_other.y);
}

Point &Point::operator=(const Point &_other)
{
	const_cast<Fixed&>(x) = Fixed(_other.x);
	const_cast<Fixed&>(y) = Fixed(_other.y);
	return *this;
}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}
