#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat()
{
	const_cast<std::string&>(name) = "Bureaucrat";
	grade = 150;
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

Bureaucrat::Bureaucrat(const Bureaucrat& _other)
{
	*this = _other;
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
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::LoseGrade()
{
	if (grade > 150)
		--grade;
	else
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(int _reason, const std::string& _name) const
{
	switch (_reason) {
		case 0 : std::cout << "\x1b[1;37m" << name << " signed " << _name << ".\n\x1b[0m";
			break;
		case 1 : std::cout << "\x1b[1;37m" << name << " couldn't sign " << _name << " because it's already signed.\n\x1b[0m";
			break;
		case 2 : std::cout << "\x1b[1;37m" << name << " couldn't sign " << _name << " because his grade is too low.\n\x1b[0m";
			break;
		default: std::cout << "\x1b[1;37m" << name << " couldn't sign " << _name << " because unknown reason.\n\x1b[0m";
	}
}

