#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

bool ScalarConverter::atod(const std::string &_str, double &_result, double _min, double _max)
{
	int _i = 0;
	bool _negative = false;
	_result = 0;

	if (_str[_i] == '-')
	{
		_negative = true;
		++_i;
	}
	else if (_str[_i] == '+')
		++_i;

	while (std::isdigit(_str[_i]))
	{
		_result = _result * 10 + (_str[_i] - '0');
		++_i;
	}

	if (_str[_i++] == '.') {
		double fraction = 0.0;
		int fractionDigits = 0;
		while (std::isdigit(_str[_i]))
		{
			fraction = fraction * 10 + (_str[_i] - '0');
			fractionDigits++;
			++_i;
		}
		_result += fraction / pow(10, fractionDigits);
	}

	if (_result >= _max || _result <= _min)
		return false;

	if (_negative)
		_result = -_result;

	return true;
}

bool ScalarConverter::convertFromBrut(ScalarConverter::Data &_data, const std::string &_str)
{
	if (_str == "+inf" || _str == "+inff")
	{
		_data.f = Converted<float>(true, 0, "+inf");
		_data.d = Converted<double>(true, 0, "+inf");
		return true;
	}
	else if (_str == "-inf" || _str == "-inff")
	{
		_data.f = Converted<float>(true, 0, "-inf");
		_data.d = Converted<double>(true, 0, "-inf");
		return true;
	}
	else if (_str == "nan" || _str == "nanf")
	{
		_data.f = Converted<float>(true, 0, "nan");
		_data.d = Converted<double>(true, 0, "nan");
		return true;
	}
	return false;
}

bool ScalarConverter::convertFromChar(ScalarConverter::Data &_data, const std::string &_str)
{
	if (_str.length() != 1 || (_str[0] >= '0' && _str[0] <= '9'))
		return false;

	_data.c = Converted<char>(true, _str[0]);
	_data.i = Converted<int>(true, static_cast<int>(_str[0]));
	_data.f = Converted<float>(true, static_cast<float>(_str[0]));
	_data.d = Converted<double>(true, static_cast<double>(_str[0]));
	return true;
}

bool ScalarConverter::convertFromInt(ScalarConverter::Data &_data, const std::string &_str)
{
	double _convert = 0.0;
	_data.i.status = atod(_str, _convert, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

	if (!_data.i.status)
		return false;

	_data.i.data = static_cast<int>(_convert);
	if (_data.i.data > 127 || _data.i.data < -127)
		_data.c = Converted<char>(false);
	else
		_data.c = Converted<char>(true, static_cast<char>(_data.i.data));
	_data.f = Converted<float>(true, static_cast<float>(_convert));
	_data.d = Converted<double>(true, _convert);
	return true;
}

bool ScalarConverter::convertFromFloat(ScalarConverter::Data &_data, const std::string &_str)
{
	double _convert = 0.0;
	_data.f.status = atod(_str, _convert, std::numeric_limits<float>::min(), std::numeric_limits<float>::max());

	if (!_data.f.status)
		return false;

	_data.f.data = static_cast<float>(_convert);
	_data.d = Converted<double>(true, _convert);
	return true;
}

bool ScalarConverter::convertFromDouble(ScalarConverter::Data &_data, const std::string &_str)
{
	_data.d.status = atod(_str, _data.d.data, std::numeric_limits<double>::min(), std::numeric_limits<double>::max());
	return _data.f.status;
}

int ScalarConverter::getPrecision(const std::string &_str)
{
	size_t _precision;

	_precision = _str.find('.');
	if (_precision != std::string::npos)
	{
		if (_str[_str.length() - 1] == 'f')
			_precision = _str.length() - (_precision + 2);
		else
			_precision = _str.length() - (_precision + 1);
	}
	else
		_precision = 1;

	return _precision;
}

void ScalarConverter::showConvert(ScalarConverter::Data &_data)
{
	if (_data.c.status)
	{
		if (isprint(_data.c.data))
			std::cout << "\x1b[1;37mchar: '" << _data.c.data << "'\x1b[0m"  << std::endl;
		else
			std::cout << "\x1b[1;37mchar: Non displayable\x1b[0m" << std::endl;
	}
	else
		std::cout << "\x1b[1;37mchar: impossible\x1b[0m" << std::endl;

	if (_data.i.status)
		std::cout << "\x1b[1;37mint: " << _data.i.data << "\x1b[0m" << std::endl;
	else
		std::cout << "\x1b[1;37mint: impossible\x1b[0m" << std::endl;

	if (_data.f.status)
	{
		if (_data.f.brut != "")
			std::cout << "\x1b[1;37mfloat: " << _data.f.brut << "f\x1b[0m" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(_data.precision) << "\x1b[1;37mfloat: " << _data.f.data << "f\x1b[0m" << std::endl;
	}
	else
		std::cout << "\x1b[1;37mfloat: impossible\x1b[0m" << std::endl;

	if (_data.d.status)
	{
		if (_data.d.brut != "")
			std::cout << "\x1b[1;37mdouble: " << _data.d.brut << "\x1b[0m" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(_data.precision) << "\x1b[1;37mdouble: " << _data.d.data << "\x1b[0m" << std::endl;
	}
	else
		std::cout << "\x1b[1;37mdouble: impossible\x1b[0m" << std::endl;
}

bool ScalarConverter::parseArgs(const std::string &_str)
{
	int _point = 0;

	if (!isdigit(_str[0]) && _str[0] != '+' && _str[0] != '-')
	{
		if (_str.length() == 1)
			return true;
		else if (_str.length() != 1)
		{
			std::cerr << "\x1b[1;31mparse: character need to be alone\x1b[0m" << std::endl;
			return false;
		}
	}

	if (!isdigit(_str[_str.length() - 1]) && _str[_str.length() - 1] != 'f')
	{
		std::cerr << "\x1b[1;31mparse: final character should be digit or f\x1b[0m" << std::endl;
		return false;
	}

	for (size_t _i = 0; _i < _str.length(); _i++)
	{
		if (!isdigit(_str[_i]) && _str[_i] != '.' && _i + 1 < _str.length())
		{
            if (_str[_i] == 'f' && _i + 1 == _str.length())
                continue;

            if ((_str[_i] == '+' || _str[_i] == '-') && _i == 0)
                continue;

			std::cerr << "\x1b[1;31mparse: there is stranded character\x1b[0m" << std::endl;
			return false;
		}
	}

	for (size_t _i = 0; _i < _str.length(); _i++)
	{
		if (_str[_i] == '.')
		{
			_point++;
			if (_point > 1)
			{
				std::cerr << "\x1b[1;31mparse: multiple points\x1b[0m" << std::endl;
				return false;
			}
			else if (_i + 1 == _str.length())
			{
				std::cerr << "\x1b[1;31mparse: point misplaced\x1b[0m" << std::endl;
				return false;
			}
			else if (!isdigit(_str[_i + 1]))
			{
				std::cerr << "\x1b[1;31mparse: point misplaced\x1b[0m" << std::endl;
				return false;
			}
		}
	}

	return true;
}

void ScalarConverter::convert(const std::string &_str)
{
	Data _data;

    if (convertFromBrut(_data, _str))
    {
        _data.precision = getPrecision(_str);
        showConvert(_data);
        return;
    }

	if (!parseArgs(_str))
		return;

    if (!convertFromChar(_data, _str))
        if (!convertFromInt(_data, _str))
            if (!convertFromFloat(_data, _str))
                convertFromDouble(_data, _str);

    _data.precision = getPrecision(_str);
    showConvert(_data);
}