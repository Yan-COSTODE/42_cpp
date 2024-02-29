#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		~ScavTrap();
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap& _other);
		ScavTrap& operator=(const ScavTrap& _other);
		virtual void attack(const std::string& target);
		void guardGate();
};

#endif
