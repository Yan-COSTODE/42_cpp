#include "MateriaSource.hpp"

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i])
			delete materia[i];
	}
}

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &_other)
{
	for (int i = 0; i < 4; i++)
	{
		if (_other.materia[i])
			materia[i] = _other.materia[i]->clone();
		else
			materia[i] = NULL;
	}

	for (int i = 0; i < 4; i++)
	{
		if (_other.materia[i])
			delete _other.materia[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &_other)
{
	for (int i = 0; i < 4; i++)
	{
		if (_other.materia[i])
			materia[i] = _other.materia[i]->clone();
		else
			materia[i] = NULL;
	}

	for (int i = 0; i < 4; i++)
	{
		if (_other.materia[i])
			delete _other.materia[i];
	}

	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	int _index;

	for (_index = 0; _index < 4; _index++)
		if (!materia[_index])
			break;

	if (_index == 4) {
		std::cout << "\x1b[1;31mNo more place for a materia\x1b[0m" << std::endl;
		return;
	}

	materia[_index] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
		if (materia[i] && materia[i]->getType() == type)
			return materia[i]->clone();

	return NULL;
}
