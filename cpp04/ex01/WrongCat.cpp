#include "WrongCat.hpp"

WrongCat::~WrongCat()
{
	std::cout << "\x1b[1;31mWrongCat Destructor called\x1b[0m" << std::endl;
}

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "\x1b[1;32mWrongCat Default constructor called\x1b[0m" << std::endl;
	type = "Cat";
}

WrongCat::WrongCat(const WrongCat &_other)
{
	std::cout << "\x1b[1;32mWrongCat Copy constructor called\x1b[0m" << std::endl;
	*this = _other;
}

WrongCat &WrongCat::operator=(const WrongCat &_other)
{
	WrongAnimal::operator=(_other);
	std::cout << "\x1b[1;32mWrongCat Copy assignment constructor called\x1b[0m" << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "\x1b[1;37mWOOOOOOOOOOF !!!!!!!!!!\x1b[0m" << std::endl;
}