#include "HumanA.hpp"

HumanA::~HumanA()
{
}

HumanA::HumanA()
{
	name = "HumanA";
	weapon = new Weapon();
}

HumanA::HumanA(std::string _name, Weapon &_weapon)
{
	name = _name;
	weapon = &_weapon;
}

void HumanA::attack()
{
	std::cout << "\x1b[1;37m" << name << " attack with their " << weapon->getType() << "\x1b[0m" << std::endl;
}
