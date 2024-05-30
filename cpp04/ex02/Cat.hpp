#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"
#include "AAnimal.hpp"

class Cat : public AAnimal {
	private:
		Brain* brain;

	public:
		~Cat();
		Cat();
		Cat(const Cat& _other);
		Cat& operator=(const Cat& _other);
		virtual void makeSound() const;
};

#endif
