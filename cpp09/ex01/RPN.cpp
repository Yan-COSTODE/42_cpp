#include "RPN.hpp"

RPN::~RPN()
{
}

RPN::RPN()
{
}

RPN::RPN(const RPN &_other)
{
    *this = _other;
}

RPN &RPN::operator=(const RPN &_other)
{
    values = _other.values;
    return *this;
}

void RPN::Calculate(std::string _prompt)
{
    std::istringstream _iss(_prompt);
    std::string _word;

    while(_iss >> _word)
    {
        if (_word.length() != 1 || (!isdigit(_word[0]) && _word[0] != '-' && _word[0] != '+'&& _word[0] != '*'&& _word[0] != '/'))
        {
            std::cerr << "\x1b[1;31mError: unknown character\x1b[0m" << std::endl;
            return;
        }

        char _char = _word[0];

        if (isdigit(_char))
            values.push(_char - '0');
        else if (!Execute(_char))
            return;
    }

    if (values.size() == 1)
        std::cout << "\x1b[1;37m" << values.top() << "\x1b[0m" << std::endl;
    else
        std::cerr << "\x1b[1;31mError: wrong expression syntax\x1b[0m" << std::endl;
}

bool RPN::Execute(char _operator)
{
    int _result = 0;

    if (values.size() < 2)
    {
        std::cerr << "\x1b[1;31mError: no number available for operation => " << _operator << "\x1b[0m" << std::endl;
        return false;
    }

    int _second = values.top();
    values.pop();
    int _first = values.top();
    values.pop();

    switch (_operator)
    {
        case '+': _result = _first + _second;
            break;
        case '-': _result = _first - _second;
            break;
        case '*': _result = _first * _second;
            break;
        case '/': if (_second == 0)
            {
                std::cerr << "\x1b[1;31mError: can't divide by 0\x1b[0m" << std::endl;
                return false;
            }
            _result = _first / _second;
            break;
    }

    values.push(_result);
    return true;
}