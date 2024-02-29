#include "Fixed.hpp"

Fixed::~Fixed()
{
	std::cout << "\x1b[1;31mDestructor called" << std::endl;
}

Fixed::Fixed()
{
	std::cout << "\x1b[1;32mDefault constructor called\x1b[0m" << std::endl;
	value = 0;
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
