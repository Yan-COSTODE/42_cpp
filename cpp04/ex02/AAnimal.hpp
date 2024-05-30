#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal {
	protected:
		std::string type;

	public:
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		virtual std::string getType() const;
};

#endif
