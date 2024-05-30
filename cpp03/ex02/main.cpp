#include "FragTrap.hpp"

int main(void)
{
	FragTrap _robot = FragTrap("Robot");
	_robot.highFivesGuys();

	for (int i = 0; i < 54; i++)
	{
		_robot.takeDamage(21);
		_robot.attack("Human");
		_robot.beRepaired(20);
	}
}