#pragma once
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		~Cure();
		Cure();
		Cure(std::string const &_type);
		Cure(const Cure& _other);
		Cure& operator=(const Cure& _other);
		virtual AMateria* clone() const;
		virtual void use(ICharacter& _target);
};

#endif
