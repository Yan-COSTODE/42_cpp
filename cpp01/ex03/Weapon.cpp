#include "Weapon.hpp"
#include <iostream>

Weapon::~Weapon()
{
}

Weapon::Weapon()
{
	type = "Weapon";
}

Weapon::Weapon(std::string _type)
{
	type = _type;
}

const std::string Weapon::getType()
{
	return type;
}

void Weapon::setType(const std::string _type)
{
	type = _type;
}
