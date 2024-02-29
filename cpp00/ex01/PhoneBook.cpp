#include "PhoneBook.hpp"

PhoneBook::~PhoneBook()
{
}

PhoneBook::PhoneBook()
{
	currentContact = -1;
	firstAdded = -1;
	added = 0;
}

void PhoneBook::ShowContact(int _index)
{
	if (_index > currentContact)
		std::cout << "\x1b[1;31mWrong Index\x1b[0m" << std::endl;
	else
		std::cout << contacts[_index].ToString() << std::endl;
}

void PhoneBook::ShowAllContact()
{
	for (int i = 0; i <= currentContact; i++)
		std::cout << contacts[i].ToStringLine(i) << std::endl;
}

void PhoneBook::AddContact()
{
	std::string _firstName, _lastName, _nickName, _phoneNumber, _darkestSecret;

	int _index = currentContact + 1;

	if (_index > 7)
		_index = firstAdded;

	std::cout << "\n\x1b[1;32mFirst Name: \x1b[0;32m";
	getline(std::cin, _firstName);
	std::cout << "\x1b[1;32mLast Name: \x1b[0;32m";
	getline(std::cin,_lastName);
	std::cout << "\x1b[1;32mNickname: \x1b[0;32m";
	getline(std::cin,_nickName);
	std::cout << "\x1b[1;32mPhone Number: \x1b[0;32m";
	getline(std::cin,_phoneNumber);
	std::cout << "\x1b[1;32mDarkest Secret: \x1b[0;32m";
	getline(std::cin,_darkestSecret);

	if (_firstName.empty() || _lastName.empty() || _nickName.empty() || _phoneNumber.empty() || _darkestSecret.empty())
	{
		std::cout << "\x1b[1;31mAll the fields aren't correct\x1b[0m" << std::endl;
		return;
	}

	contacts[_index] = Contact(_firstName, _lastName, _nickName, _phoneNumber, _darkestSecret);
	++added;
	if (currentContact < 7)
		++currentContact;
	if (currentContact == 7 && added == 8)
		firstAdded = (_index + 1) % 8;
}


void PhoneBook::SearchContact()
{
	std::string _input;
	int _index;

	if (currentContact == -1)
	{
		std::cout << "\n\x1b[1;35mThe PhoneBook is empty\x1b[0m" << std::endl;
		return;
	}
	std::cout << "\n\x1b[1;35mHere is your contact list\x1b[0m\n";
	ShowAllContact();
	std::cout << "\n\x1b[1;35mType index to inspect: \x1b[0;35m";
	getline(std::cin, _input);
	std::stringstream _ss(_input);
	_ss >> _index;

	if (_ss.fail())
		std::cout << "\x1b[1;31mWrong Index\x1b[0m" << std::endl;
	else
		ShowContact(_index);
}
