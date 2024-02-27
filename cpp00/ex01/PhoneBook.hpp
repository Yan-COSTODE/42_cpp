#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int currentContact;
		int firstAdded;
		int added;

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
