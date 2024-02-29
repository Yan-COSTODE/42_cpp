#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal()
{
	std::cout << "\x1b[1;31mWrongAnimal Destructor called\x1b[0m" << std::endl;
}

WrongAnimal::WrongAnimal()
{
	std::cout << "\x1b[1;32mWrongAnimal Default constructor called\x1b[0m" << std::endl;
	type = "Animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &_other)
{
	std::cout << "\x1b[1;32mWrongAnimal Copy constructor called\x1b[0m" << std::endl;
	type = _other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &_other)
{
	std::cout << "\x1b[1;32mWrongAnimal Copy assignment constructor called\x1b[0m" << std::endl;
	type = _other.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "\x1b[1;32m* LOUD SOUND *\x1b[0m" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}
