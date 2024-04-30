#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

template<typename T>
void ScalarConverter::stringToNumeric(Converted<T> &_converted, const std::string &_str)
{
	std::stringstream ss(_str);
	ss >> _converted.data;
	_converted.status = !ss.fail();
}

void ScalarConverter::convert(const std::string &_str)
{
	size_t precision;
	Converted<char> _c = Converted<char>(false, 0);
	Converted<int> _i = Converted<int>(false, 0);
	Converted<float> _f = Converted<float>(false, 0);
	Converted<double> _d = Converted<double>(false, 0);

	precision = _str.find('.');
	if (precision != std::string::npos)
	{
		if (_str[_str.length() - 1] == 'f')
			precision = _str.length() - (precision + 2);
		else
			precision = _str.length() - (precision + 1);
	}
	else
		precision = 1;
	stringToNumeric<int>(_i, _str);
	stringToNumeric<float>(_f, _str);
	stringToNumeric<double>(_d, _str);
	if (_i.status)
	{
		_c.status = true;
		_c.data = _i.data;
	}

	if (_c.status)
	{
		if (isprint(_c.data))
			std::cout << "\x1b[1;37mchar: '" << _c.data << "'\n\x1b[0m";
		else
			std::cout << "\x1b[1;37mchar: Non displayable\n\x1b[0m";
	}
	else
		std::cout << "\x1b[1;37mchar: impossible\n\x1b[0m";

	if (_i.status)
		std::cout << "\x1b[1;37mint: " << _i.data << "\n\x1b[0m";
	else
		std::cout << "\x1b[1;37mint: impossible\n\x1b[0m";

	if (_f.status)
		std::cout << std::fixed << std::setprecision(precision) << "\x1b[1;37mfloat: " << _f.data << "f\n\x1b[0m";
	else
		std::cout << "\x1b[1;37mfloat: impossible\n\x1b[0m";

	if (_d.status)
		std::cout << std::fixed << std::setprecision(precision) << "\x1b[1;37mdouble: " << _d.data << "\n\x1b[0m";
	else
		std::cout << "\x1b[1;37mdouble: impossible\n\x1b[0m";
}