#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string name;

public:
	~DiamondTrap();
	DiamondTrap();
	DiamondTrap(std::string _name);
	DiamondTrap(const DiamondTrap& _other);
	DiamondTrap& operator=(const DiamondTrap& _other);
	virtual void attack(const std::string &target);
	void whoAmI();
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
