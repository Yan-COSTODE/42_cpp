#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;

	protected:
		bool hasHitPoints();
		bool hasEnergyPoints();

	public:
		~ClapTrap();
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap& _other);
		ClapTrap& operator=(const ClapTrap& _other);
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
