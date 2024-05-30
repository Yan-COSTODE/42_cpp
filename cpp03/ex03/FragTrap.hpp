#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <stdlib.h>
#define GETLINE(_input) if (!std::getline(std::cin, _input)) {std::cerr << "\x1b[1;31m\nError: Failed to read input.\x1b[0m" << std::endl; exit (EXIT_FAILURE);}

class FragTrap : virtual public ClapTrap {
	public:
		~FragTrap();
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap& _other);
		FragTrap& operator=(const FragTrap& _other);
		void highFivesGuys(void);
};

#endif
