#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm()
{
	const_cast<std::string&>(target) = "target";
	const_cast<std::string&>(name) = "Presidential Pardon";
	status = false;
	const_cast<int&>(gradeSign) = 25;
	const_cast<int&>(gradeExec) = 5;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &_target)
{
    const_cast<std::string&>(target) = _target;
    const_cast<std::string&>(name) = "Presidential Pardon";
    status = false;
    const_cast<int&>(gradeSign) = 25;
    const_cast<int&>(gradeExec) = 5;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &_other) : AForm(_other)
{
	*this = _other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &_other)
{
	const_cast<std::string&>(target) = _other.target;
	const_cast<std::string&>(name) = _other.name;
	status = _other.status;
	const_cast<int&>(gradeSign) = _other.gradeSign;
	const_cast<int&>(gradeExec) = _other.gradeExec;
	return *this;
}

void PresidentialPardonForm::executeAction()
{
	std::cout << "\x1b[1;37m" << target << " has been pardoned by Zaphod Beeblebrox.\n\x1b[0m";
}