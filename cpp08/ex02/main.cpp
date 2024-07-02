#include "MutantStack.hpp"
#include <iostream>

void CheckTop(MutantStack<int>& _stack)
{
    std::cout << "\x1b[1;37m== Top Function ==\x1b[0m" << std::endl;
    _stack.push(5);
    std::cout << "[" << _stack.top() << "]" << std::endl;
    _stack.push(17);
    std::cout << "[" << _stack.top() << "]" << std::endl;
    _stack.pop();
    std::cout << "[" << _stack.top() << "]" << std::endl;
    _stack.push(17);
    std::cout << "[" << _stack.top() << "]" << std::endl;
}

void CheckSize(MutantStack<int>& _stack)
{
    std::cout << "\x1b[1;37m\n== Size Function ==\x1b[0m" << std::endl;
    _stack.push(2);
    std::cout << "[" << _stack.size() << "]" << std::endl;
    _stack.push(41);
    std::cout << "[" << _stack.size() << "]" << std::endl;
    _stack.pop();
    std::cout << "[" << _stack.size() << "]" << std::endl;
    _stack.push(41);
    std::cout << "[" << _stack.size() << "]" << std::endl;
}

void CheckIterator(MutantStack<int>& _stack)
{
    std::cout << "\x1b[1;37m\n== Iterator Operation ==\x1b[0m" << std::endl;
    for(MutantStack<int>::iterator it = _stack.begin(); it != _stack.end(); it++)
        std::cout << "[" << *it << "]";

    std::cout << std::endl;
}

void CheckRIterator(MutantStack<int>& _stack)
{
    std::cout << "\x1b[1;37m\n== Reverse Iterator Operation ==\x1b[0m" << std::endl;
    for(MutantStack<int>::reverse_iterator it = _stack.rbegin(); it != _stack.rend(); it++)
        std::cout << "[" << *it << "]";

    std::cout << std::endl;
}

int main()
{
    MutantStack<int> stack;

    CheckTop(stack);
    CheckSize(stack);

    stack.push(3);
    stack.push(9);
    stack.push(737);
    stack.push(0);

    CheckIterator(stack);
    CheckRIterator(stack);
    std::stack<int> s(stack);
    return 0;
}
