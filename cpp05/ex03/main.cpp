#include "Intern.hpp"

int main()
{
	Intern intern;
	Bureaucrat boss;
	AForm	*rrf;
	std::string input;

	boss = Bureaucrat("Boss", 1);
	do {
		std::cout << "\x1b[1;37mWrite the name of the form you want\nSay exit to Quit\nInput : \x1b[0m";
		std::getline(std::cin, input);
		rrf = intern.makeForm(input, "Bender");
		if (rrf)
		{
			rrf->beSigned(boss);
			rrf->execute(boss);
			delete rrf;
		}
	} while (input != "exit");
}