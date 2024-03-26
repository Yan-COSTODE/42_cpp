#include "Bureaucrat.hpp"

void TooLow()
{
	try {
		Bureaucrat low("Low", 151);
		std::cout << low << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void TooHigh()
{
	try {
		Bureaucrat high("High", 0);
		std::cout << high << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void GoLow()
{
	try {
		Bureaucrat low("Low", 150);
		std::cout << low << std::endl;
		low.LoseGrade();
		std::cout << low << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void GoHigh()
{
	try {
		Bureaucrat high("High", 1);
		std::cout << high << std::endl;
		high.GainGrade();
		std::cout << high << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

int main()
{
	TooLow();
	TooHigh();
	GoLow();
	GoHigh();
}