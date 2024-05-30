#include "Animal.hpp"

Animal::~Animal()
{
	std::cout << "\x1b[1;31mAnimal Destructor called\x1b[0m" << std::endl;
}

Animal::Animal()
{
	std::cout << "\x1b[1;32mAnimal Default constructor called\x1b[0m" << std::endl;
	type = "Animal";
}

Animal::Animal(const Animal &_other)
{
	std::cout << "\x1b[1;32mAnimal Copy constructor called\x1b[0m" << std::endl;
	type = _other.type;
}

Animal &Animal::operator=(const Animal &_other)
{
	std::cout << "\x1b[1;32mAnimal Copy assignment constructor called\x1b[0m" << std::endl;
	type = _other.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "\x1b[1;37m* LOUD SILENCE *\x1b[0m" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
