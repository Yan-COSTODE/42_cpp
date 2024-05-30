#include "Cat.hpp"

Cat::~Cat()
{
	std::cout << "\x1b[1;31mCat Destructor called\x1b[0m" << std::endl;
	delete brain;
}

Cat::Cat() : AAnimal()
{
	std::cout << "\x1b[1;32mCat Default constructor called\x1b[0m" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &_other)
{
	std::cout << "\x1b[1;32mCat Copy constructor called\x1b[0m" << std::endl;
	*this = _other;
}

Cat &Cat::operator=(const Cat &_other)
{
	AAnimal::operator=(_other);
	std::cout << "\x1b[1;32mCat Copy assignment constructor called\x1b[0m" << std::endl;
	brain = new Brain();
	*brain = *_other.brain;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "\x1b[1;37mMEEEOOOOOOOW !!!!!!!!!!\x1b[0m" << std::endl;
}