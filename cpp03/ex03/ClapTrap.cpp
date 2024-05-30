#include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{
	std::cout << "\x1b[1;31mClapTrap Destructor called\x1b[0m" << std::endl;
}

ClapTrap::ClapTrap()
{
	std::cout << "\x1b[1;32mClapTrap Default constructor called\x1b[0m" << std::endl;
	name = "ClapTrap";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string _name)
{
	std::cout << "\x1b[1;32mClapTrap String constructor called\x1b[0m" << std::endl;
	name = _name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &_other)
{
	std::cout << "\x1b[1;32mClapTrap Copy constructor called\x1b[0m" << std::endl;
	*this= _other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &_other)
{
	std::cout << "\x1b[1;32mClapTrap Copy assignment constructor called\x1b[0m" << std::endl;
	name = _other.name;
	hitPoints = _other.hitPoints;
	energyPoints = _other.energyPoints;
	attackDamage = _other.attackDamage;
	return *this;
}

bool ClapTrap::hasHitPoints()
{
	if (hitPoints == 0)
	{
		std::cout << "\x1b[1;31mClapTrap " << name << " can't perform any actions he's dead.\x1b[0m" << std::endl;
		return false;
	}

	return true;
}

bool ClapTrap::hasEnergyPoints()
{
	if (energyPoints == 0)
	{
		std::cout << "\x1b[1;31mClapTrap " << name << " can't perform any actions he's out of energy.\x1b[0m" << std::endl;
		return false;
	}

	return true;
}

void ClapTrap::attack(const std::string &target)
{
	if (!hasHitPoints() || !hasEnergyPoints())
		return;

	energyPoints--;
	std::cout << "\x1b[1;37mClapTrap " << name << " attack " << target << ", causing " << attackDamage << " points of damage !\x1b[0m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "\x1b[1;37mClapTrap " << name << " is already dead, do you really want to hit a corpse ?\x1b[0m" << std::endl;
		return;
	}

	if (amount >= hitPoints)
	{
		std::cout << "\x1b[1;37mClapTrap " << name << " took " << hitPoints << " damage, he has now 0HP\x1b[0m" << std::endl;
		hitPoints = 0;
		return;
	}

	hitPoints -= amount;
	std::cout << "\x1b[1;37mClapTrap " << name << " took " << amount << " damage, he has now " << hitPoints <<"HP.\x1b[0m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!hasHitPoints() || !hasEnergyPoints())
		return;

	hitPoints += amount;
	energyPoints--;
	std::cout << "\x1b[1;37mClapTrap " << name << " repaired himself and gained " << amount << "HP, he has now " << hitPoints << "HP.\x1b[0m" << std::endl;
}

