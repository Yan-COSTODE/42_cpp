#include "HumanB.hpp"

HumanB::~HumanB()
{
}

HumanB::HumanB()
{
	name = "HumanB";
	weapon = NULL;
}

HumanB::HumanB(std::string _name)
{
	name = _name;
	weapon = NULL;
}

void HumanB::attack()
{
	if (weapon)
		std::cout << "\x1b[1;37m" << name << " attack with their " << weapon->getType() << "\x1b[0m" << std::endl;
	else
		std::cout << "\x1b[1;37m" << name << " attack without weapon\x1b[0m" << std::endl;
}

void HumanB::setWeapon(Weapon &_weapon)
{
	weapon = &_weapon;
}
