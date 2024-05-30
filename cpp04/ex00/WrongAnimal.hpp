#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
	protected:
		std::string type;

	public:
		virtual ~WrongAnimal();
		WrongAnimal();
		WrongAnimal(const WrongAnimal& _other);
		WrongAnimal& operator=(const WrongAnimal& _other);
		void makeSound() const;
		std::string getType() const;
};

#endif
