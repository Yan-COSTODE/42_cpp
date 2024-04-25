#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
	class GradeTooHighException : public std::exception	{
		virtual const char *what() const throw()
		{
			return "AForm : Grade is too high!";
		}
	};

	class GradeTooLowException : public std::exception	{
		virtual const char *what() const throw()
		{
			return "AForm : Grade is too low!";
		}
	};

	class NotSignedException : public std::exception	{
		virtual const char *what() const throw()
		{
			return "AForm : The form isn't signed!";
		}
	};

	protected:
		const std::string name;
		bool status;
		const int gradeSign;
		const int gradeExec;

	public:
		~AForm();
		AForm();
		AForm(const AForm& _other);
		AForm(const std::string& _name, int _gradeSign, int _gradeExec);
		AForm& operator=(const AForm& _other);
		const std::string& getName() const;
		bool getStatus() const;
		const int& getGradeSign() const;
		const int& getGradeExec() const;
		void beSigned(const Bureaucrat& _bureaucrat);
		void execute(const Bureaucrat& _bureaucrat);
		virtual void executeAction() = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& _bureaucrat);

#endif
