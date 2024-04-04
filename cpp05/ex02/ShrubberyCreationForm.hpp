#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const std::string target;

	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& _other);
		ShrubberyCreationForm(const std::string& _target);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& _other);
		void executeAction();
};

#endif
