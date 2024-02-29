#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria {
	protected:
		std::string type;

	public:
		virtual ~AMateria();
		AMateria();
		AMateria(std::string const &_type);
		AMateria(const AMateria& _other);
		AMateria& operator=(const AMateria& _other);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& _target);
};

#endif
