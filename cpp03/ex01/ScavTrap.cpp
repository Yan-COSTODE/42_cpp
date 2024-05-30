#include "ScavTrap.hpp"

ScavTrap::~ScavTrap()
{
	std::cout << "\x1b[1;31mScavTrap Destructor called\x1b[0m" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "\x1b[1;32mScavTrap Default constructor called\x1b[0m" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "\x1b[1;32mScavTrap String constructor called\x1b[0m" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &_other)
{
	std::cout << "\x1b[1;32mScavTrap Copy constructor called\x1b[0m" << std::endl;
	*this = _other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &_other)
{
	ClapTrap::operator=(_other);
	std::cout << "\x1b[1;32mScavTrap Copy assignment constructor called\x1b[0m" << std::endl;
	return *this;
}


void ScavTrap::guardGate()
{
	if (!hasHitPoints() || !hasEnergyPoints())
		return;

	energyPoints--;
	std::cout << "\x1b[1;37mScavTrap " << name << " is in Gatekeeper mode.\x1b[0m" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!hasHitPoints() || !hasEnergyPoints())
		return;

	energyPoints--;
	std::cout << "\x1b[1;37mScavTrap " << name << " attack " << target << ", causing " << attackDamage << " points of damage !\x1b[0m" << std::endl;
}
