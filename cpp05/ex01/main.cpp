#include "Form.hpp"

void TooLow()
{
	try {
		Bureaucrat bureaucrat("Michel", 150);
		std::cout << bureaucrat << std::endl;
		Form form("BTP", 100, 50);
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		form.beSigned(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void Normal()
{
	try {
		Bureaucrat bureaucrat("Michel", 50);
		std::cout << bureaucrat << std::endl;
		Form form("BTP", 100, 50);
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		form.beSigned(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

int main()
{
	TooLow();
	Normal();
}