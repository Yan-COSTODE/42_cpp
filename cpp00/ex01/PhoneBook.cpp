#include "PhoneBook.hpp"

PhoneBook::~PhoneBook()
{
}

PhoneBook::PhoneBook()
{
	currentContact = -1;
}

void PhoneBook::ShowContact(int _index)
{
	int _max = currentContact >= 8 ? 7 : currentContact;

	if (_index > _max)
		std::cout << "\x1b[1;31mWrong Index\x1b[0m" << std::endl;
	else
		std::cout << contacts[_index].ToString() << std::endl;
}

void PhoneBook::ShowAllContact()
{
	int _max = currentContact >= 8 ? 7 : currentContact;

	for (int i = 0; i <= _max; i++)
		std::cout << contacts[i].ToStringLine(i) << std::endl;
}

void PhoneBook::AddContact()
{
	std::string _firstName, _lastName, _nickName, _phoneNumber, _darkestSecret;
	int _index = (currentContact + 1) % 8;

	std::cout << "\n\x1b[1;32mFirst Name: \x1b[0;32m";
	GETLINE(_firstName)
	std::cout << "\x1b[1;32mLast Name: \x1b[0;32m";
	GETLINE(_lastName)
	std::cout << "\x1b[1;32mNickname: \x1b[0;32m";
	GETLINE(_nickName)
	std::cout << "\x1b[1;32mPhone Number: \x1b[0;32m";
	GETLINE(_phoneNumber)
	std::cout << "\x1b[1;32mDarkest Secret: \x1b[0;32m";
	GETLINE(_darkestSecret)

	if (_firstName.empty() || _lastName.empty() || _nickName.empty() || _phoneNumber.empty() || _darkestSecret.empty())
	{
		std::cout << "\x1b[1;31mAll the fields aren't correct\x1b[0m" << std::endl;
		return;
	}

	contacts[_index] = Contact(_firstName, _lastName, _nickName, _phoneNumber, _darkestSecret);
	++currentContact;
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
	GETLINE(_input)
	std::stringstream _ss(_input);
	_ss >> _index;

	if (_ss.fail())
		std::cout << "\x1b[1;31mWrong Index\x1b[0m" << std::endl;
	else
		ShowContact(_index);
}
