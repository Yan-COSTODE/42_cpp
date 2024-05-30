#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal* _animals[3];
	_animals[0] = new Animal();
	_animals[1] = new Dog();
	_animals[2] = new Cat();

	std::cout << std::endl << "\x1b[1;37m--- ANIMAL ---\x1b[0m" << std::endl;
	for (int _i = 0; _i < 3; _i++)
	{
		std::cout << _animals[_i]->getType() << " " << std::endl;
		_animals[_i]->makeSound();
	}

	delete _animals[0];
	delete _animals[2];

	_animals[0] = _animals[1];
	_animals[2] = _animals[1];

	std::cout << std::endl << "\x1b[1;37m--- DOG COPIED ---\x1b[0m" << std::endl;
	for (int _i = 0; _i < 3; _i++)
	{
		std::cout << _animals[_i]->getType() << " " << std::endl;
		_animals[_i]->makeSound();
	}

	delete _animals[1];

	return 0;
}
