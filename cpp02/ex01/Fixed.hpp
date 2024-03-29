#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int value;
		static const int fractional = 8;

	public:
		~Fixed();
		Fixed();
		Fixed(const int _value);
		Fixed(const float _value);
		Fixed(const Fixed& _other);
		Fixed& operator=(const Fixed& _other);
		friend std::ostream& operator<<(std::ostream& _output, const Fixed& _other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

#endif
