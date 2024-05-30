#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <stdlib.h>
#define GETLINE(_input) if (!std::getline(std::cin, _input)) {std::cerr << "\x1b[1;31m\nError: Failed to read input.\x1b[0m" << std::endl; exit (EXIT_FAILURE);}

class PhoneBook {
	private:
		Contact contacts[8];
		int currentContact;

	private:
		void ShowContact(int _index);
		void ShowAllContact();

	public:
		PhoneBook();
		~PhoneBook();
		void AddContact();
		void SearchContact();

};

#endif
