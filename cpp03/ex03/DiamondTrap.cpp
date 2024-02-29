#include "DiamondTrap.hpp"

DiamondTrap::~DiamondTrap()
{
	std::cout << "\x1b[1;31mDiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap()
{
	std::cout << "\x1b[1;32mDiamondTrap Default constructor called" << std::endl;
	name = "ClapTrap";
	ScavTrap::name = name + "_clap_name";
	ScavTrap::hitPoints = FragTrap::hitPoints;
	ScavTrap::energyPoints = ScavTrap::energyPoints;
	ScavTrap::attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string _name)
{
	std::cout << "\x1b[1;32mDiamondTrap String constructor called" << std::endl;
	name = _name;
	ScavTrap::name = name + "_clap_name";
	ScavTrap::hitPoints = FragTrap::hitPoints;
	ScavTrap::energyPoints = ScavTrap::energyPoints;
	ScavTrap::attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &_other)
{
	std::cout << "\x1b[1;32mDiamondTrap Copy constructor called" << std::endl;
	name = _other.name;
	ScavTrap::name = _other.ScavTrap::name;
	ScavTrap::hitPoints = _other.FragTrap::hitPoints;
	ScavTrap::energyPoints = _other.ScavTrap::energyPoints;
	ScavTrap::attackDamage = _other.FragTrap::attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &_other)
{
	std::cout << "\x1b[1;32mDiamondTrap Copy assignment constructor called" << std::endl;
	name = _other.name;
	ScavTrap::name = _other.ScavTrap::name;
	ScavTrap::hitPoints = _other.FragTrap::hitPoints;
	ScavTrap::energyPoints = _other.ScavTrap::energyPoints;
	ScavTrap::attackDamage = _other.FragTrap::attackDamage;
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	ScavTrap::beRepaired(amount);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	ScavTrap::takeDamage(amount);
}


void DiamondTrap::whoAmI()
{
	std::cout << "\x1b[1;37mDiamondTrap is " << name << " and " << ScavTrap::name << ".\x1b[0m" << std::endl;
}
