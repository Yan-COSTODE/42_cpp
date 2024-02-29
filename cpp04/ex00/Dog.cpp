#include "Dog.hpp"

Dog::~Dog()
{
	std::cout << "\x1b[1;31mDog Destructor called\x1b[0m" << std::endl;
}

Dog::Dog() : Animal()
{
	std::cout << "\x1b[1;32mDog Default constructor called\x1b[0m" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &_other) : Animal(_other)
{
	std::cout << "\x1b[1;32mDog Copy constructor called\x1b[0m" << std::endl;
}

Dog &Dog::operator=(const Dog &_other)
{
	Animal::operator=(_other);
	std::cout << "\x1b[1;32mDog Copy assignment constructor called\x1b[0m" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "\x1b[1;32mWOOOOOOOOOOF !!!!!!!!!!\x1b[0m" << std::endl;
}
