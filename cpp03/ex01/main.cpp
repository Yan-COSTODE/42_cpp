#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap _robot = ScavTrap("Robot");

	for (int i = 0; i < 20; i++)
	{
		_robot.takeDamage(23);
		_robot.attack("Human");
		_robot.guardGate();
		_robot.beRepaired(20);
	}
}