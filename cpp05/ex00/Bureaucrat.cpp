#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat()
{
	const_cast<std::string&>(name) = "Bureaucrat";
	grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& _other)
{
	const_cast<std::string&>(name) = _other.name;
	grade = _other.grade;
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade)
{
	const_cast<std::string&>(name) = _name;
	if (_grade > 150)
		throw GradeTooLowException();
	if (_grade < 1)
		throw GradeTooHighException();
	grade = _grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &_other)
{
	const_cast<std::string&>(name) = _other.name;
	grade = _other.grade;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& _bureaucrat)
{
	os << "\x1b[1;37m" << _bureaucrat.getName() << ", bureaucrat grade " << _bureaucrat.getGrade() << ".\x1b[0m";
	return os;
}


const std::string& Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::GainGrade()
{
	if (grade < 1)
		++grade;
	else
		throw GradeTooHighException();
}

void Bureaucrat::LoseGrade()
{
	if (grade > 150)
		--grade;
	else
		throw GradeTooLowException();
}
