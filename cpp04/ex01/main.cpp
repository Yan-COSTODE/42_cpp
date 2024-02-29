#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* _dog = new Dog();
	const Animal* _cat = new Cat();

	std::cout << _dog->getType() << " " << std::endl;
	_dog->makeSound();
	std::cout << _cat->getType() << " " << std::endl;
	_cat->makeSound();

	delete _dog;
	delete _cat;
	return 0;
}
