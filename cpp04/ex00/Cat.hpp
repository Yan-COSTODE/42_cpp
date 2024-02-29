#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		~Cat();
		Cat();
		Cat(const Cat& _other);
		Cat& operator=(const Cat& _other);
		virtual void makeSound() const;
};

#endif
