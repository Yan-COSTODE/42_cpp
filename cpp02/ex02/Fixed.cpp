#include "Fixed.hpp"

Fixed::~Fixed()
{
}

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const int _value)
{
	value = _value << fractional;
}

Fixed::Fixed(const float _value)
{
	value = roundf(_value * (1 << fractional));
}

Fixed::Fixed(const Fixed &_other)
{
	value = _other.value;
}

Fixed &Fixed::operator=(const Fixed &_other)
{
	value = _other.value;
	return *this;
}

Fixed &Fixed::operator++()
{
	++value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed _tmp = *this;
	++value;
	return _tmp;
}

Fixed &Fixed::operator--()
{
	--value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed _tmp = *this;
	--value;
	return _tmp;
}

Fixed Fixed::operator+(const Fixed &_other)
{
	return Fixed(toFloat() + _other.toFloat());
}

Fixed Fixed::operator-(const Fixed &_other)
{
	return Fixed(toFloat() - _other.toFloat());
}

Fixed Fixed::operator*(const Fixed &_other)
{
	return Fixed(toFloat() * _other.toFloat());
}

Fixed Fixed::operator/(const Fixed &_other)
{
	return Fixed(toFloat() / _other.toFloat());
}

bool Fixed::operator>(const Fixed &_other) const
{
	return toFloat() > _other.toFloat();
}

bool Fixed::operator<(const Fixed &_other) const
{
	return toFloat() < _other.toFloat();
}

bool Fixed::operator>=(const Fixed &_other) const
{
	return toFloat() >= _other.toFloat();
}

bool Fixed::operator<=(const Fixed &_other) const
{
	return toFloat() <= _other.toFloat();
}

bool Fixed::operator==(const Fixed &_other) const
{
	return toFloat() == _other.toFloat();
}

bool Fixed::operator!=(const Fixed &_other) const
{
	return toFloat() != _other.toFloat();
}

std::ostream& operator<<(std::ostream &_output, const Fixed &_other)
{
	_output << _other.toFloat();
	return _output;
}

Fixed &Fixed::min(Fixed &_one, Fixed &_two)
{
	if (_one > _two)
		return _two;
	return _one;
}

const Fixed &Fixed::min(const Fixed &_one, const Fixed &_two)
{
	if (_one > _two)
		return _two;
	return _one;
}

Fixed &Fixed::max(Fixed &_one, Fixed &_two)
{
	if (_one > _two)
		return _one;
	return _two;
}

const Fixed &Fixed::max(const Fixed &_one, const Fixed &_two)
{
	if (_one > _two)
		return _one;
	return _two;
}

int Fixed::getRawBits() const
{
	return value;
}

void Fixed::setRawBits(int const raw)
{
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
