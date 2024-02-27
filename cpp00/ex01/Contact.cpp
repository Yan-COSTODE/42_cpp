#include "Contact.hpp"

Contact::~Contact()
{
}

Contact::Contact()
{
	firstName = "First Name";
	lastName = "Last Name";
	nickName = "Nickname";
	phoneNumber = "Phone Number";
	darkestSecret = "Darkest Secret";
}

Contact::Contact(std::string _firstName, std::string _lastName, std::string _nickName, std::string _phoneNumber, std::string _darkestSecret)
{
	firstName = _firstName;
	lastName = _lastName;
	nickName = _nickName;
	phoneNumber = _phoneNumber;
	darkestSecret = _darkestSecret;
}

std::string Contact::IntToString(int _number)
{
	std::stringstream _ss;
	_ss << _number;
	return _ss.str();
}

std::string Contact::ToStringElem(std::string _elem)
{
	const int _width = 10;

	if (_elem.length() >= 10)
		return _elem.substr(0, _width - 1) + ".";
	return _elem.insert(0, _width - _elem.length(), ' ');
}

std::string Contact::ToStringLine(int _index)
{
	std::string _result;

	_result += "\x1b[0;35m";
	_result += ToStringElem(IntToString(_index));
	_result += "\x1b[1;35m|\x1b[0;35m";
	_result += ToStringElem(firstName);
	_result += "\x1b[1;35m|\x1b[0;35m";
	_result += ToStringElem(lastName);
	_result += "\x1b[1;35m|\x1b[0;35m";
	_result += ToStringElem(nickName);
	_result += "\x1b[0m";

	return _result;
}

std::string Contact::ToString()
{
	std::string _result;

	_result += "\x1b[1;35mFirst Name: \x1b[0;35m";
	_result += firstName;
	_result += "\n\x1b[1;35mLast Name: \x1b[0;35m";
	_result += lastName;
	_result += "\n\x1b[1;35mNickname: \x1b[0;35m";
	_result += nickName;
	_result += "\n\x1b[1;35mPhone Number: \x1b[0;35m";
	_result += phoneNumber;
	_result += "\n\x1b[1;35mDarkest Secret: \x1b[0;35m";
	_result += darkestSecret;

	return _result;
}