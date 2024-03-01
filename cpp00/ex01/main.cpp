#include "PhoneBook.hpp"

int main()
{
	std::string input;
	PhoneBook phoneBook = PhoneBook();

	std::cout << "\x1b[1;37mYou are on the Awesome PhoneBook" << std::endl;
	std::cout << "Type \x1b[1;32mADD\x1b[1;37m to add a new contact" << std::endl;
	std::cout << "Type \x1b[1;35mSEARCH\x1b[1;37m to search a contact" << std::endl;
	std::cout << "Type \x1b[1;31mEXIT\x1b[1;37m to quit\x1b[0m";

	do
	{
		std::cout << "\n\x1b[1;37mType here: \x1b[0m";
		getline(std::cin, input);
		if (input == "ADD")
			phoneBook.AddContact();
		else if (input == "SEARCH")
			phoneBook.SearchContact();
		else if (input != "EXIT")
			std::cout << "\x1b[1;31mWrong Input\x1b[0m" << std::endl;
	} while (input != "EXIT");
}
