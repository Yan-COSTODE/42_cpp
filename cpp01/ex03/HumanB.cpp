#include "HumanB.hpp"

HumanB::~HumanB()
{
}

HumanB::HumanB()
{
	name = "HumanB";
	weapon = new Weapon();
}

HumanB::HumanB(std::string _name)
{
	name = _name;
	weapon = new Weapon();
}

void HumanB::attack()
{
	std::cout << "\x1b[1;37m" << name << " attack with their " << weapon->getType() << "\x1b[0m" << std::endl;
}

void HumanB::setWeapon(Weapon &_weapon)
{
	delete weapon;
	weapon = &_weapon;
}
