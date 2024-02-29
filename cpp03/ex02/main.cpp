#include "FragTrap.hpp"

int main(void)
{
	FragTrap _robot = FragTrap("Robot");
	_robot.highFivesGuys();

	for (int i = 0; i < 10; i++)
	{
		_robot.attack("Human");
		_robot.takeDamage(3);
		_robot.beRepaired(2);
	}
}