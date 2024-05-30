#include "Zombie.hpp"

int main(void)
{
	Zombie _gneu("Gneu");
	_gneu.announce();
	Zombie *_barbie = newZombie("Barbie");
	_barbie->announce();
	randomChump("Ken");
	delete _barbie;
}