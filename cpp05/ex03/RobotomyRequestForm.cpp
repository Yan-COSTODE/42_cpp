#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm()
{
	const_cast<std::string&>(target) = "target";
	const_cast<std::string&>(name) = "Robotomy Request";
	status = false;
	const_cast<int&>(gradeSign) = 72;
	const_cast<int&>(gradeExec) = 45;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &_target)
{
    const_cast<std::string&>(target) = _target;
    const_cast<std::string&>(name) = "Robotomy Request";
    status = false;
    const_cast<int&>(gradeSign) = 72;
    const_cast<int&>(gradeExec) = 45;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &_other) : AForm(_other)
{
	*this = _other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &_other)
{
	const_cast<std::string&>(target) = _other.target;
	const_cast<std::string&>(name) = _other.name;
	status = _other.status;
	const_cast<int&>(gradeSign) = _other.gradeSign;
	const_cast<int&>(gradeExec) = _other.gradeExec;
	return *this;
}

void RobotomyRequestForm::executeAction()
{
	std::cout << "\x1b[1;37mMakes some drilling noises...\n\x1b[0m";
	srand(time(NULL));
	int _random = rand() % 100;
	if (_random < 50)
		std::cout << "\x1b[1;37m" << target << " has been robotomized successfully.\n\x1b[0m";
	else
		std::cout << "\x1b[1;37mRobotomy failed for " << target << ".\n\x1b[0m";
}