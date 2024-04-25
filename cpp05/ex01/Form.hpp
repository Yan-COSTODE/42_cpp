#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	class GradeTooHighException : public std::exception	{
		virtual const char *what() const throw()
		{
			return "Form : Grade is too high!";
		}
	};

	class GradeTooLowException : public std::exception	{
		virtual const char *what() const throw()
		{
			return "Form : Grade is too low!";
		}
	};

	private:
		const std::string name;
		bool status;
		const int gradeSign;
		const int gradeExec;

	public:
		~Form();
		Form();
		Form(const Form& _other);
		Form(const std::string& _name, int _gradeSign, int _gradeExec);
		Form& operator=(const Form& _other);
		const std::string& getName() const;
		bool getStatus() const;
		const int& getGradeSign() const;
		const int& getGradeExec() const;
		void beSigned(const Bureaucrat& _bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& _bureaucrat);

#endif
