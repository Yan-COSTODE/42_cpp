#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *materia[4];

	public:
		~MateriaSource();
		MateriaSource();
		MateriaSource(const MateriaSource& _other);
		MateriaSource& operator=(const MateriaSource& _other);
		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
};

#endif
