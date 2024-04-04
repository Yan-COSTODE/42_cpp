#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string target;

	public:
		~PresidentialPardonForm();
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& _other);
		PresidentialPardonForm(const std::string& _target);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& _other);
		void executeAction();
};

#endif
