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
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		Fixed& operator=(const Fixed& _other);
		Fixed operator+(const Fixed& _other);
		Fixed operator-(const Fixed& _other);
		Fixed operator*(const Fixed& _other);
		Fixed operator/(const Fixed& _other);
		bool operator>(const Fixed& _other) const;
		bool operator<(const Fixed& _other) const;
		bool operator>=(const Fixed& _other) const;
		bool operator<=(const Fixed& _other) const;
		bool operator==(const Fixed& _other) const;
		bool operator!=(const Fixed& _other) const;
		static Fixed& min(Fixed& _one, Fixed& _two);
		static const Fixed& min(const Fixed& _one, const Fixed& _two);
		static Fixed& max(Fixed& _one, Fixed& _two);
		static const Fixed& max(const Fixed& _one, const Fixed& _two);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
};

std::ostream& operator<<(std::ostream& _output, const Fixed& _other);

#endif
