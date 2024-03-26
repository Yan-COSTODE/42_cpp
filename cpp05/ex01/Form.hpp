#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Form {
	private:
		const string name;
		bool status;
		const int gradeSign;
		const int gradeExec;

	public:
		~Form();
		Form();
		Form(const Form& _other);
		Form(const std::string& _name, int _grade);
		Form& operator=(const Form& _other);
		friend std::ostream& operator<<(std::ostream& os, const Form& _bureaucrat);
		const std::string& getName() const;
		bool getStatus() const;
		const int& getGradeSign() const;
		const int& getGradeExec() const;
		beSigned(const Bureaucrat& _bureaucrat);
};

#endif
