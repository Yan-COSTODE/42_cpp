#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap _robot = ClapTrap("Robot");

	for (int i = 0; i < 10; i++)
	{
		_robot.attack("Human");
		_robot.takeDamage(3);
		_robot.beRepaired(2);
	}
}