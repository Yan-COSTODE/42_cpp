#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap _robot = ClapTrap("Robot");

	for (int i = 0; i < 8; i++)
	{
		_robot.takeDamage(3);
		_robot.attack("Human");
		_robot.beRepaired(2);
	}
}