#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;

	public:
		~Zombie();
		Zombie();
		Zombie(std::string _name);
		void announce();
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
