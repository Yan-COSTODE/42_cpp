#include "Cat.hpp"

Cat::~Cat()
{
	std::cout << "\x1b[1;31mCat Destructor called\x1b[0m" << std::endl;
	delete brain;
}

Cat::Cat() : Animal()
{
	std::cout << "\x1b[1;32mCat Default constructor called\x1b[0m" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &_other)  : Animal(_other)
{
	std::cout << "\x1b[1;32mCat Copy constructor called\x1b[0m" << std::endl;
	brain = _other.brain;
}

Cat &Cat::operator=(const Cat &_other)
{
	Animal::operator=(_other);
	std::cout << "\x1b[1;32mCat Copy assignment constructor called\x1b[0m" << std::endl;
	brain = _other.brain;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "\x1b[1;32mMEEEOOOOOOOW !!!!!!!!!!\x1b[0m" << std::endl;
}