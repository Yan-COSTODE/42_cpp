#pragma once
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		~Ice();
		Ice();
		Ice(std::string const &_type);
		Ice(const Ice& _other);
		Ice& operator=(const Ice& _other);
		virtual AMateria* clone() const;
		virtual void use(ICharacter& _target);
};

#endif
