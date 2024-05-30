#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string name;

	public:
		~DiamondTrap();
		DiamondTrap();
		DiamondTrap(std::string _name);
		DiamondTrap(const DiamondTrap& _other);
		DiamondTrap& operator=(const DiamondTrap& _other);
		void whoAmI();

		using ClapTrap::beRepaired;
		using ScavTrap::attack;
		using ScavTrap::takeDamage;
		using ScavTrap::guardGate;
		using FragTrap::highFivesGuys;
};

#endif
