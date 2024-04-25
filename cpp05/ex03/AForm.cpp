#include "AForm.hpp"

AForm::~AForm()
{
}

AForm::AForm() : gradeSign(150), gradeExec(150)
{
	const_cast<std::string&>(name) = "AForm";
	status = false;
}

AForm::AForm(const AForm& _other) : gradeSign(_other.gradeSign), gradeExec(_other.gradeExec)
{
	const_cast<std::string&>(name) = _other.name;
	status = _other.status;
}

AForm::AForm(const std::string& _name, int _gradeSign, int _gradeExec) : gradeSign(_gradeSign), gradeExec(_gradeExec)
{
	const_cast<std::string&>(name) = _name;
	status = false;
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
}

AForm &AForm::operator=(const AForm &_other)
{
	const_cast<std::string&>(name) = _other.name;
	status = _other.status;
	const_cast<int&>(gradeSign) = _other.gradeSign;
	const_cast<int&>(gradeExec) = _other.gradeExec;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& _form)
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

const std::string& AForm::getName() const
{
	return name;
}
bool AForm::getStatus() const
{
	return status;
}
const int& AForm::getGradeSign() const
{
	return gradeSign;
}
const int& AForm::getGradeExec() const
{
	return gradeExec;
}

void AForm::beSigned(const Bureaucrat &_bureaucrat)
{
	if (status)
		_bureaucrat.signForm(1, *this);
	else if (_bureaucrat.getGrade() <= gradeSign)
	{
		status = true;
		_bureaucrat.signForm(0, *this);
	}
	else
	{
		_bureaucrat.signForm(2, *this);
		throw AForm::GradeTooLowException();
	}
}

void AForm::execute(const Bureaucrat &_bureaucrat)
{
	if (!status) {
		_bureaucrat.executedForm(*this);
		throw AForm::NotSignedException();
	}
	else if (_bureaucrat.getGrade() <= gradeExec)
	{
		_bureaucrat.executedForm(*this);
		executeAction();
	}
	else
	{
		_bureaucrat.executedForm(*this);
		throw AForm::GradeTooLowException();
	}
}