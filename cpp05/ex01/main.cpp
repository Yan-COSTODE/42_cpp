#include "Form.hpp"

void TooLowCreation()
{
    try {
        Bureaucrat bureaucrat("Michel", 150);
        std::cout << bureaucrat << std::endl;
        Form form("BTP", 160, 50);
        std::cout << form << std::endl;
        form.beSigned(bureaucrat);
        form.beSigned(bureaucrat);
    }
    catch (std::exception& e) {
        std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
    }
}

void TooHighCreation()
{
    try {
        Bureaucrat bureaucrat("Michel", 150);
        std::cout << bureaucrat << std::endl;
        Form form("BTP", 0, 50);
        std::cout << form << std::endl;
        form.beSigned(bureaucrat);
        form.beSigned(bureaucrat);
    }
    catch (std::exception& e) {
        std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
    }
}

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
    std::cout << "\x1b[1;37m----- Grade too low -----\x1b[0m" << std::endl;
    TooLowCreation();
    std::cout << std::endl;
    std::cout << "\x1b[1;37m----- Grade too high -----\x1b[0m" << std::endl;
    TooHighCreation();
    std::cout << std::endl;
    std::cout << "\x1b[1;37m----- Can't Sign -----\x1b[0m" << std::endl;
    TooLow();
    std::cout << std::endl;
    std::cout << "\x1b[1;37m----- All Good -----\x1b[0m" << std::endl;
    Normal();
}