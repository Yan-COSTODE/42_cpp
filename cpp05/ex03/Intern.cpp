#include "Intern.hpp"

Intern::~Intern()
{
}

Intern::Intern()
{
}

Intern::Intern(const Intern& _other)
{
	(void)_other;
}

Intern &Intern::operator=(const Intern &_other)
{
	(void)_other;
	return *this;
}

AForm *Intern::makeForm(const std::string &_name, const std::string &_target)
{
	static const std::string _constructors[] = {"shrubbery", "robotomy","presidential",
						 "shrubbery creation" , "robotomy request", "presidential pardon",
						 "shrubbery form", "robotomy form", "presidential form",
						 "shrubbery creation form", "robotomy request form", "presidential pardon form"};

	for(int _i = 0; _i < 12; _i++)
	{
		if (_constructors[_i] == ToLower(_name))
		{
			switch (_i % 3)
			{
				case 0 : std::cout << "\x1b[1;37mIntern creates Shrubbery Creation Form.\n\x1b[0m";
					return (new ShrubberyCreationForm(_target));
				case 1 : std::cout << "\x1b[1;37mIntern creates Robotomy Request Form.\n\x1b[0m";
					return (new RobotomyRequestForm(_target));
				case 2 : std::cout << "\x1b[1;37mIntern creates Presidential Pardon Form.\n\x1b[0m";
					return (new PresidentialPardonForm(_target));
			}
		}
	}

	std::cout << "\x1b[1;31mIntern can't creates " << _name << ", it doesn't exist.\n\x1b[0m";
	return NULL;
}

std::string Intern::ToLower(const std::string &_str)
{
	std::string _final = _str;

	for (size_t _i = 0; _i < _final.length(); _i++)
		_final[_i] = std::tolower(_final[_i]);

	return _final;
}