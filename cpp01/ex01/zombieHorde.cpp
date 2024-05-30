#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *_zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
		_zombies[i] = Zombie(name);

	return (_zombies);
}