#include "Character.hpp"
#include "AMateria.hpp"

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i])
			delete materia[i];
	}

	List *current, *tmp;

	current = destroy;
	while (current)
	{
		tmp = current;
		current = current->next;
		delete tmp->value;
		delete tmp;
	}
}

Character::Character()
{
	destroy = NULL;
	name = "Character";

	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}

Character::Character(std::string const &_name)
{
	name = _name;
	destroy = NULL;

	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}

Character::Character(const Character &_other)
{
	*this = _other;
}

Character &Character::operator=(const Character &_other)
{
	destroy = _other.destroy;
	name = _other.name;

	for (int i = 0; i < 4; i++)
	{
		if (materia[i])
			delete materia[i];
	}

	for (int i = 0; i < 4; i++)
	{
		if (_other.materia[i])
			materia[i] = _other.materia[i]->clone();
		else
			materia[i] = NULL;
	}

	return *this;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
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

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0 || !materia[idx])
	{
		std::cout << "\x1b[1;31mNothing to unequip here\x1b[0m" << std::endl;
		return;
	}

	if (!destroy)
		destroy = new List(materia[idx]);
	else
	{
		List *last;

		last = destroy;
		while (last->next)
			last = last->next;
		last->next = new List(materia[idx]);
	}

	materia[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx > 3 || idx < 0 || !materia[idx])
	{
		std::cout << "\x1b[1;31mNothing to use here\x1b[0m" << std::endl;
		return;
	}

	materia[idx]->use(target);
}
