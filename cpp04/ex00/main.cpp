#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* _animal = new Animal();
	const Animal* _dog = new Dog();
	const Animal* _cat = new Cat();
	const WrongAnimal* _wrongCat = new WrongCat();

	std::cout << _animal->getType() << " " << std::endl;
	_animal->makeSound();
	std::cout << _dog->getType() << " " << std::endl;
	_dog->makeSound();
	std::cout << _cat->getType() << " " << std::endl;
	_cat->makeSound();
	std::cout << _wrongCat->getType() << " " << std::endl;
	_wrongCat->makeSound();

	delete _animal;
	delete _dog;
	delete _cat;
	delete _wrongCat;
	return 0;
}