#include "Fixed.hpp"

Fixed::~Fixed()
{
	std::cout << "\x1b[1;31mDestructor called\x1b[0m" << std::endl;
}

Fixed::Fixed()
{
	std::cout << "\x1b[1;32mDefault constructor called\x1b[0m" << std::endl;
	value = 0;
}

Fixed::Fixed(const int _value)
{
	std::cout << "\x1b[1;32mInt constructor called\x1b[0m" << std::endl;
	value = _value << fractional;
}

Fixed::Fixed(const float _value)
{
	std::cout << "\x1b[1;32mFloat constructor called\x1b[0m" << std::endl;
	value = roundf(_value * (1 << fractional));
}

Fixed::Fixed(const Fixed &_other)
{
	std::cout << "\x1b[1;32mCopy constructor called\x1b[0m" << std::endl;
	value = _other.value;
}

Fixed &Fixed::operator=(const Fixed &_other)
{
	std::cout << "\x1b[1;32mCopy assignment operator called\x1b[0m" << std::endl;
	value = _other.value;
	return (*this);
}

std::ostream& operator<<(std::ostream &_output, const Fixed &_other)
{
	_output << _other.toFloat();
	return _output;
}


int Fixed::getRawBits() const
{
	std::cout << "\x1b[1;37mgetRawBits member function called\x1b[0m" << std::endl;
	return value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "\x1b[1;37msetRawBits member function called\x1b[0m" << std::endl;
	value = raw;
}

float Fixed::toFloat() const
{
	return (float)value / (float)(1 << fractional);
}

int Fixed::toInt() const
{
	return value >> fractional;
}
