#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	private:
		std::string ToStringElem(std::string _elem);
		std::string IntToString(int _number);

	public:
		~Contact();
		Contact();
		Contact(std::string _firstName, std::string _lastName, std::string _nickName, std::string _phoneNumber, std::string _darkestSecret);
		std::string ToStringLine(int _index);
		std::string ToString();
};

#endif
