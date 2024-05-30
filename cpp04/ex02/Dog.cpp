#include "Dog.hpp"

Dog::~Dog()
{
	std::cout << "\x1b[1;31mDog Destructor called\x1b[0m" << std::endl;
	delete brain;
}

Dog::Dog() : AAnimal()
{
	std::cout << "\x1b[1;32mDog Default constructor called\x1b[0m" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &_other)
{
	std::cout << "\x1b[1;32mDog Copy constructor called\x1b[0m" << std::endl;
	*this = _other;
}

Dog &Dog::operator=(const Dog &_other)
{
	AAnimal::operator=(_other);
	std::cout << "\x1b[1;32mDog Copy assignment constructor called\x1b[0m" << std::endl;
	brain = new Brain();
	*brain = *_other.brain;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "\x1b[1;37mWOOOOOOOOOOF !!!!!!!!!!\x1b[0m" << std::endl;
}