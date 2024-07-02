#include "BitcoinExchange.hpp"

~BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange()
{
    InitData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& _other)
{
  *this = _other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& _other)
{
  data = _other.data;
  return *this;
}

void BitcoinExchange::InitData()
{
    std::ifstream _file("data.csv");

    if (!_file.is_open())
    {
        std::cerr << "\x1b[1;31mError: could not open data file\x1b[0m" << std::endl;
        return;
    }

    std::string _line;
    std::getline(_file, _line);
    std::string _separator = GetSeparator(_line, "date", "exchange_rate");

    if (_separator.empty())
    {
        std::cerr << "\x1b[1;31mError: could not parse data file\x1b[0m" << std::endl;
        return;
    }

    while(std::getline(_file, _line))
    {
        size_t _pos = _line.find_first_of(_separator);

        if (_pos == std::string::npos)
        {
            std::cerr << "\x1b[1;31mError: no separator found => [" << _separator << "]\x1b[0m" << std::endl;
            return;
        }

        std::string _key = _line.substr(0, _pos);
        std::string _valueString = _line.substr(_pos + _separator.length());
        std::stringstream _ss(_valueString);
        float _value;

        if (_ss >> _value)
            data[_key] = _value;
    }

    _file.close();
}

void BitcoinExchange::GetData(std::string _fileName)
{
    if (data.empty())
    {
        std::cerr << "\x1b[1;31mError: no data available\x1b[0m" << std::endl;
        return;
    }

    ParseFile(_fileName);
}

void BitcoinExchange::ParseFile(std::string _fileName)
{
    std::ifstream _file(_fileName.c_str());

    if (!_file.is_open())
    {
        std::cerr << "\x1b[1;31mError: could not open input file\x1b[0m" << std::endl;
        return;
    }

    std::string _line;
    std::getline(_file, _line);
    std::string _separator = GetSeparator(_line, "date", "value");

    if (_separator.empty())
    {
        std::cerr << "\x1b[1;31mError: could not parse input file\x1b[0m" << std::endl;
        return;
    }

    while(std::getline(_file, _line))
        ParseLine(_line, _separator);

    _file.close();
}

void BitcoinExchange::ParseLine(std::string _line, std::string _separator)
{
    size_t _pos = _line.find_first_of(_separator);

    if (_pos == std::string::npos)
    {
        std::cerr << "\x1b[1;31mError: bad input => " << _line << "\x1b[0m" << std::endl;
        return;
    }

    std::string _date = _line.substr(0, _pos);

    if (!IsValidDate(_date))
    {
        std::cerr << "\x1b[1;31mError: not valid date => " << _date << "\x1b[0m" << std::endl;
        return;
    }

    std::string _valueString = _line.substr(_pos + _separator.length());

    if (!_valueString.empty() && _valueString[0] == '-')
    {
        std::cerr << "\x1b[1;31mError: not a positive number => " << _valueString << "\x1b[0m" << std::endl;
        return;
    }

    std::stringstream _ss(_valueString);
    float _value;

    if (_ss >> _value)
    {
        if ((int)_value > std::numeric_limits<int>::max() || (int)_value < 0)
        {
            std::cerr << "\x1b[1;31mError: too large a number => " << _valueString << "\x1b[0m" << std::endl;
            return;
        }

        float _mult = GetNearestMult(_date);

        if (_mult == -1)
        {
            std::cerr << "\x1b[1;31mError: no date can't be found near => " << _date << "\x1b[0m" << std::endl;
            return;
        }

        _value *= _mult;
        std::cout << "\x1b[1;37m" << _date << " => " << _valueString << " = " << _value << "\x1b[0m" << std::endl;
    }
    else
    {
        std::cerr << "\x1b[1;31mError: can't comprehend this number => " << _valueString << "\x1b[0m" << std::endl;
        return;
    }
}

std::string BitcoinExchange::GetSeparator(std::string _line, std::string _first, std::string _second)
{
    std::string _separator;

    size_t _firstPos = _line.find(_first);

    if (_firstPos == std::string::npos)
        return "";

    size_t _secondPos = _line.find(_second, _firstPos);

    if (_secondPos == std::string::npos)
        return "";

    _firstPos += _first.length();
    return _line.substr(_firstPos, _secondPos - _firstPos);
}

bool BitcoinExchange::IsLeapYear(int _year)
{
    return (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
}

bool BitcoinExchange::IsValidDate(int _year, int _month, int _day)
{
    if (_year < 1 || _month < 1 || _month > 12 || _day < 1)
        return false;

    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (_month == 2 && IsLeapYear(_year))
        return _day <= 29;
    else
        return _day <= daysInMonth[_month - 1];
}

bool BitcoinExchange::IsValidDate(std::string _date)
{
    std::istringstream ss(_date);
    int year, month, day;
    char delim1, delim2;

    if (ss >> year >> delim1 >> month >> delim2 >> day) {
        if (delim1 == '-' && delim2 == '-' && IsValidDate(year, month, day)) {
            return true;
        }
    }

    return false;
}

float BitcoinExchange::GetNearestMult(std::string _date)
{
    if (data[_date])
        return data[_date];

    _date = GetPrecedentDay(_date);

    if (_date.empty())
        return -1;

    return GetNearestMult(_date);
}

std::string BitcoinExchange::GetPrecedentDay(std::string _date)
{
    std::tm _tm = {};

    if (strptime(_date.c_str(), "%Y-%m-%d", &_tm) == NULL)
        return "";

    _tm.tm_mday -= 1;
    std::mktime(&_tm);
    char _buffer[11];
    strftime(_buffer, sizeof(_buffer), "%Y-%m-%d", &_tm);
    return std::string(_buffer);
}
