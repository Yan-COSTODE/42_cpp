#include <string>
#include <iostream>

int main(void)
{
	std::string _brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &_brain;
	std::string& stringREF = _brain;

	std::cout << "\x1b[1;37mMemory address of the string variable: " << &_brain << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl << std::endl;
	std::cout << "Value of the string variable: " << _brain << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << "\x1b[0m" << std::endl;

	return 0;
}