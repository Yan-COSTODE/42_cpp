#include "Intern.hpp"

#include <stdlib.h>
#define GETLINE(_input) if (!std::getline(std::cin, _input)) {std::cerr << "\x1b[1;31m\nError: Failed to read input.\x1b[0m" << std::endl; exit (EXIT_FAILURE);}

int main()
{
	Intern intern;
	Bureaucrat boss;
	AForm	*rrf;
	std::string input;

	boss = Bureaucrat("Boss", 1);

	do {
		std::cout << "\x1b[1;37mWrite the name of the form you want\nSay exit to Quit\nInput : \x1b[0m";
        GETLINE(input)
        std::cout << std::endl;
		rrf = intern.makeForm(input, "Bender");

		if (rrf)
		{
			rrf->beSigned(boss);
			rrf->execute(boss);
			delete rrf;
		}

        std::cout << std::endl;
	} while (input != "exit");
}