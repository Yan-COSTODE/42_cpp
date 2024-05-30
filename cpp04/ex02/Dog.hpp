#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "AAnimal.hpp"

class Dog : public AAnimal {
	private:
		Brain* brain;

	public:
		~Dog();
		Dog();
		Dog(const Dog& _other);
		Dog& operator=(const Dog& _other);
		virtual void makeSound() const;
};

#endif