#include "iter.hpp"
#include <iostream>

template<typename T>
void printValue(T _value)
{
    std::cout << "[" << _value << "]" << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    double darr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string sarr[] = {"1", "2", "3", "4", "5"};

    std::cout << "\x1b[1;37m== Int ==\x1b[0m" << std::endl;
    iter(arr, 5, printValue);

    std::cout << "\x1b[1;37m\n== Double ==\x1b[0m" << std::endl;
    iter(darr, 5, printValue);

    std::cout << "\x1b[1;37m\n== String ==\x1b[0m" << std::endl;
    iter(sarr, 5, printValue);
    return 0;
}