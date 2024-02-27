#include "HumanA.hpp"

HumanA::~HumanA()
{
}

HumanA::HumanA()
{
	name = "HumanA";
	weapon = Weapon();
}

HumanA::HumanA(std::string _name, Weapon _weapon)
{
	name = _name;
	weapon = _weapon;
}
