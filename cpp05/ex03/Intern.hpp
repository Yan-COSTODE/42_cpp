#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	public:
		~Intern();
		Intern();
		Intern(const Intern& _other);
		Intern& operator=(const Intern& _other);
		AForm *makeForm(const std::string& _name, const std::string& _target);

	private:
		std::string ToLower(const std::string& _str);
};

#endif
