#include "Brain.hpp"

Brain::~Brain()
{
	std::cout << "\x1b[1;31mBrain Destructor called\x1b[0m" << std::endl;
}

Brain::Brain()
{
	std::cout << "\x1b[1;32mBrain Default constructor called\x1b[0m" << std::endl;
}

Brain::Brain(const Brain &_other)
{
	std::cout << "\x1b[1;32mBrain Copy constructor called\x1b[0m" << std::endl;

	for (int i = 0; i < 100; i++)
		ideas[i] = _other.ideas[i];
}

Brain &Brain::operator=(const Brain &_other)
{
	std::cout << "\x1b[1;32mBrain Copy assignment constructor called\x1b[0m" << std::endl;

	for (int i = 0; i < 100; i++)
		ideas[i] = _other.ideas[i];

	return *this;
}
