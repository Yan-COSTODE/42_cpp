#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		~WrongCat();
		WrongCat();
		WrongCat(const WrongCat& _other);
		WrongCat& operator=(const WrongCat& _other);
		virtual void makeSound() const;
};

#endif
