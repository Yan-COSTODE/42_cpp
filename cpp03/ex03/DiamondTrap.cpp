#include "DiamondTrap.hpp"

DiamondTrap::~DiamondTrap()
{
	std::cout << "\x1b[1;31mDiamondTrap Destructor called\x1b[0m" << std::endl;
}

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap_clap_name"), ScavTrap("DiamondTrap_clap_name"), FragTrap("DiamondTrap_clap_name"), name("DiamondTrap")
{
	std::cout << "\x1b[1;32mDiamondTrap Default constructor called\x1b[0m" << std::endl;
	FragTrap::hitPoints = 100;
	ScavTrap::energyPoints = 50;
	FragTrap::attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name"), ScavTrap(_name + "_clap_name"), FragTrap(_name + "_clap_name"), name(_name)
{
	std::cout << "\x1b[1;32mDiamondTrap String constructor called\x1b[0m" << std::endl;
	FragTrap::hitPoints = 100;
	ScavTrap::energyPoints = 50;
	FragTrap::attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &_other)
{
	std::cout << "\x1b[1;32mDiamondTrap Copy constructor called\x1b[0m" << std::endl;
	*this = _other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &_other)
{
	std::cout << "\x1b[1;32mDiamondTrap Copy assignment constructor called\x1b[0m" << std::endl;
	name = _other.name;
	ClapTrap::name = _other.ClapTrap::name;
	hitPoints = _other.hitPoints;
	energyPoints = _other.energyPoints;
	attackDamage = _other.attackDamage;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "\x1b[1;37mDiamondTrap is " << name << " and " << ClapTrap::name << ".\x1b[0m" << std::endl;
	std::cout << "\x1b[1;37mStat: " << hitPoints << "HP, " << energyPoints << "ST, " << attackDamage << "AD\x1b[0m" << std::endl;
}
