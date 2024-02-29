#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;

	public:
		~Point();
		Point();
		Point(const float _x, const float _y);
		Point(const Point& _other);
		Point& operator=(const Point& _other);
		Fixed getX() const;
		Fixed getY() const;
};

#endif
