#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		const std::string target;

	public:
		~RobotomyRequestForm();
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& _other);
		RobotomyRequestForm(const std::string& _target);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& _other);
		void executeAction();
};

#endif
