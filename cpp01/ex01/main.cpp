#include "Zombie.hpp"

int main(void)
{
	const int number = 10;
	Zombie *_zombies = zombieHorde(number, "Horde");

	for (int i = 0; i < number; i++)
		_zombies[i].announce();

	delete[] _zombies;
}