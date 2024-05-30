#include <string>
#include <iostream>

int main(void)
{
	std::string _brain = "HI THIS IS BRAIN";
	std::string* _stringPtr = &_brain;
	std::string& _stringRef = _brain;

	std::cout << "\x1b[1;37mMemory address of the string variable: " << &_brain << std::endl;
	std::cout << "Memory address held by stringPTR: " << _stringPtr << std::endl;
	std::cout << "Memory address held by stringREF: " << &_stringRef << std::endl << std::endl;
	std::cout << "Value of the string variable: " << _brain << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *_stringPtr << std::endl;
	std::cout << "Value pointed to by stringREF: " << _stringRef << "\x1b[0m" << std::endl;

	return 0;
}