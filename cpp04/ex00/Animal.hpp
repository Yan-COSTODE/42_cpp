#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string type;

	public:
		virtual ~Animal();
		Animal();
		Animal(const Animal& _other);
		Animal& operator=(const Animal& _other);
		virtual void makeSound() const;
		std::string getType() const;
};

#endif
