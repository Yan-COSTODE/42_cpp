#include "AAnimal.hpp"

AAnimal::~AAnimal()
{
	std::cout << "\x1b[1;31mAnimal Destructor called\x1b[0m" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "\x1b[1;37m* LOUD SILENCE *\x1b[0m" << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}
