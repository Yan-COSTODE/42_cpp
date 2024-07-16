#include "Form.hpp"

Form::~Form()
{
}

Form::Form() : gradeSign(150), gradeExec(150)
{
	const_cast<std::string&>(name) = "Form";
	status = false;
}

Form::Form(const std::string& _name, int _gradeSign, int _gradeExec) : gradeSign(_gradeSign), gradeExec(_gradeExec)
{
    const_cast<std::string&>(name) = _name;
    status = false;
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
}

Form::Form(const Form& _other) : gradeSign(_other.gradeSign), gradeExec(_other.gradeExec)
{
	*this = _other;
}

Form &Form::operator=(const Form &_other)
{
	const_cast<std::string&>(name) = _other.name;
	status = _other.status;
	const_cast<int&>(gradeSign) = _other.gradeSign;
	const_cast<int&>(gradeExec) = _other.gradeExec;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& _form)
{
	os << "\x1b[1;37m" << _form.getName();
	if (_form.getStatus())
		os << ", signed";
	else
		os << ", not signed";
	os << ", can be signed by at least " << _form.getGradeSign();
	os << ", can be executed by at least " << _form.getGradeExec() << ".\x1b[0m";
	return os;
}

const std::string& Form::getName() const
{
	return name;
}
bool Form::getStatus() const
{
	return status;
}
const int& Form::getGradeSign() const
{
	return gradeSign;
}
const int& Form::getGradeExec() const
{
	return gradeExec;
}

void Form::beSigned(const Bureaucrat &_bureaucrat)
{
	if (status)
		_bureaucrat.signForm(1, name);
	else if (_bureaucrat.getGrade() <= gradeSign)
	{
		status = true;
		_bureaucrat.signForm(0, name);
	}
	else
	{
		_bureaucrat.signForm(2, name);
		throw Form::GradeTooLowException();
	}
}
