#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {
	class GradeTooHighException : public std::exception	{
		virtual const char *what() const throw()
		{
			return "Grade is too high!";
		}
	};

	class GradeTooLowException : public std::exception	{
		virtual const char *what() const throw()
		{
			return "Grade is too low!";
		}
	};

	private:
		const std::string name;
		int grade;

	public:
		~Bureaucrat();
		Bureaucrat();
		Bureaucrat(const Bureaucrat& _other);
		Bureaucrat(const std::string& _name, int _grade);
		Bureaucrat& operator=(const Bureaucrat& _other);
		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& _bureaucrat);
		const std::string& getName() const;
		int getGrade() const;
		void GainGrade();
		void LoseGrade();
};

#endif
