#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(0, 0);
	Point b(0, 2);
	Point c(2, 0);
	Point point(1, 1);

	if (bsp(a, b, c, point))
		std::cout << "\x1b[1;32mPoint is in the triangle ABC\x1b[0m" << std::endl;
	else
		std::cout << "\x1b[1;31mPoint is out of the triangle ABC\x1b[0m" << std::endl;
}