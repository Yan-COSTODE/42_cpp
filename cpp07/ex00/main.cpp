#include "whatever.hpp"
#include <iostream>

int main() {
    int a = 2;
    int b = 3;

    std::cout << "\x1b[1;37m== Int ==\x1b[0m" << std::endl;
    std::cout << "\x1b[1;37m-- Swap Test --\x1b[0m" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "\x1b[1;37m-- Compare Test --\x1b[0m" << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "\x1b[1;37m\n== String ==\x1b[0m" << std::endl;
    std::cout << "\x1b[1;37m-- Swap Test --\x1b[0m" << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "\x1b[1;37m-- Compare Test --\x1b[0m" << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    return 0;
}
