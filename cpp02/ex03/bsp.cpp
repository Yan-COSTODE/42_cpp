#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point _v0 = Point(c.getX().toFloat() - a.getX().toFloat(), c.getY().toFloat() - a.getY().toFloat());
	Point _v1 = Point(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
	Point _v2 = Point(point.getX().toFloat() - a.getX().toFloat(), point.getY().toFloat() - a.getY().toFloat());

	double _dot0 = _v0.getX().toFloat() * _v0.getX().toFloat() + _v0.getY().toFloat() * _v0.getY().toFloat();
	double _dot1 = _v0.getX().toFloat() * _v1.getX().toFloat() + _v0.getY().toFloat() * _v1.getY().toFloat();
	double _dot2 = _v0.getX().toFloat() * _v2.getX().toFloat() + _v0.getY().toFloat() * _v2.getY().toFloat();
	double _dot3 = _v1.getX().toFloat() * _v1.getX().toFloat() + _v1.getY().toFloat() * _v1.getY().toFloat();
	double _dot4 = _v1.getX().toFloat() * _v2.getX().toFloat() + _v1.getY().toFloat() * _v2.getY().toFloat();

	double _invDenom = 1 / (_dot0 * _dot3 - _dot1 * _dot1);
	double _u = (_dot3 * _dot2 - _dot1 * _dot4) * _invDenom;
	double _v = (_dot0 * _dot4 - _dot1 * _dot2) * _invDenom;

	return (_u >= 0) && (_v >= 0) && (_u + _v <= 1);
}