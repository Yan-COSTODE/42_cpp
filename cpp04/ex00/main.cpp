#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* _animal = new Animal();
	const Animal* _dog = new Dog();
	const Animal* _cat = new Cat();
	const WrongAnimal* _wrongAnimal = new WrongAnimal();
	const WrongAnimal* _wrongCat = new WrongCat();

	std::cout << "\x1b[1;37m--- ANIMAL ---\x1b[0m" << std::endl;
	std::cout << _animal->getType() << std::endl;
	_animal->makeSound();
	std::cout << _dog->getType() << std::endl;
	_dog->makeSound();
	std::cout << _cat->getType() << std::endl;
	_cat->makeSound();
	std::cout << std::endl << "\x1b[1;37m--- WRONG ANIMAL ---\x1b[0m" << std::endl;
	std::cout << _wrongAnimal->getType() << std::endl;
	_wrongAnimal->makeSound();
	std::cout << _wrongCat->getType() << std::endl;
	_wrongCat->makeSound();

	delete _animal;
	delete _dog;
	delete _cat;
	delete _wrongAnimal;
	delete _wrongCat;
	return 0;
}