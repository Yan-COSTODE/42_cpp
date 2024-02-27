#include "Zombie.hpp"

int main(void)
{
	Zombie *_zombiePtr = newZombie("Zombie Ptr");
	_zombiePtr->announce();
	randomChump("Zombie No Ptr");
	delete _zombiePtr;
}