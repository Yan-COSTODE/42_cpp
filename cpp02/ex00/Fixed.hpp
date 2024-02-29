#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int value;
		static const int fractional = 8;

	public:
		~Fixed();
		Fixed();
		Fixed(const Fixed& _other);
		Fixed& operator=(const Fixed& _other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
