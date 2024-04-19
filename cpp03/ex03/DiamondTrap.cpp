#include "DiamondTrap.hpp"

DiamondTrap::~DiamondTrap()
{
	std::cout << "\x1b[1;31mDiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap()
{
	std::cout << "\x1b[1;32mDiamondTrap Default constructor called" << std::endl;
	name = "DiamondTrap";
	ClapTrap::name = name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string _name)
{
	std::cout << "\x1b[1;32mDiamondTrap String constructor called" << std::endl;
	name = _name;
	ClapTrap::name = name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &_other)
{
	std::cout << "\x1b[1;32mDiamondTrap Copy constructor called" << std::endl;
	name = _other.name;
	ClapTrap::name = _other.ClapTrap::name;
	hitPoints = _other.hitPoints;
	energyPoints = _other.energyPoints;
	attackDamage = _other.attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &_other)
{
	std::cout << "\x1b[1;32mDiamondTrap Copy assignment constructor called" << std::endl;
	name = _other.name;
	ClapTrap::name = _other.ClapTrap::name;
	hitPoints = _other.hitPoints;
	energyPoints = _other.energyPoints;
	attackDamage = _other.attackDamage;
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	ClapTrap::beRepaired(amount);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	ClapTrap::takeDamage(amount);
}

void DiamondTrap::whoAmI()
{
	std::cout << "\x1b[1;37mDiamondTrap is " << name << " and " << ClapTrap::name << ".\x1b[0m" << std::endl;
}
