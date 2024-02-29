#include "FragTrap.hpp"

FragTrap::~FragTrap()
{
	std::cout << "\x1b[1;31mFragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "\x1b[1;32mFragTrap Default constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "\x1b[1;32mFragTrap String constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &_other) : ClapTrap(_other)
{
	std::cout << "\x1b[1;32mFragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &_other)
{
	ClapTrap::operator=(_other);
	std::cout << "\x1b[1;32mFragTrap Copy assignment constructor called" << std::endl;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::string _input;

	std::cout << "\x1b[1;37mFragTrap want a high fives, do you respond (yes/no) ?" << std::endl;
	do
	{
		std::cout << "\x1b[1;37mYour response : \x1b[0m";
		std::cin >> _input;
		if (_input == "yes")
			std::cout << "\x1b[1;37mFragTrap is happy !!!\x1b[0m" << std::endl;
		else if (_input == "no")
			std::cout << "\x1b[1;37mFragTrap is sad...\x1b[0m" << std::endl;
		else
			std::cout << "\x1b[1;37mFragTrap didn't understand.\x1b[0m" << std::endl;
	} while (_input != "yes" && _input != "no");
}

