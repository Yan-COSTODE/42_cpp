#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap _robot = DiamondTrap("Robot");
	_robot.whoAmI();
	_robot.highFivesGuys();

	for (int i = 0; i < 20; i++)
	{
		_robot.takeDamage(23);
		_robot.attack("Human");
		_robot.guardGate();
		_robot.beRepaired(20);
	}
}