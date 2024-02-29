#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		~FragTrap();
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap& _other);
		FragTrap& operator=(const FragTrap& _other);
		void highFivesGuys(void);
};

#endif
