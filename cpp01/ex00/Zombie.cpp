#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << "\x1b[1;31m" << name << " destroyed\x1b[0m" << std::endl;
}

Zombie::Zombie()
{
	name = "Zombie";
}

Zombie::Zombie(std::string _name)
{
	name = _name;
}


void Zombie::announce()
{
	std::cout << "\x1b[1;37m" << name << ": BraiiiiiiinnnzzzZ...\x1b[0m" << std::endl;
}
