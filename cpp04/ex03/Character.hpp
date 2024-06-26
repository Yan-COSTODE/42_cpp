#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter {
	struct List {
		AMateria *value;
		List *next;

		List(AMateria *_value)
		{
			value = _value;
			next = NULL;
		}
	};

	private:
		std::string name;
		AMateria *materia[4];
		List *destroy;

	public:
		~Character();
		Character();
		Character(std::string const &_name);
		Character(const Character& _other);
		Character& operator=(const Character& _other);
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
