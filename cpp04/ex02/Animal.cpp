#include "Animal.hpp"

Animal::~Animal()
{
	std::cout << "\x1b[1;31mAnimal Destructor called\x1b[0m" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "\x1b[1;32m* LOUD SILENCE *\x1b[0m" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
