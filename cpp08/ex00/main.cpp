#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    std::cout << "\x1b[1;37m== Vector ==\x1b[0m" << std::endl;
    std::cout << "\x1b[1;37m[" << easyFind(vec, 3) << "]\x1b[0m" << std::endl;
    std::cout << "\x1b[1;37m[" << easyFind(vec, 1) << "]\x1b[0m" << std::endl;
    std::cout << "\x1b[1;37m[" << easyFind(vec, 5) << "]\x1b[0m" << std::endl;
    std::cout << "\x1b[1;37m[" << easyFind(vec, 6) << "]\x1b[0m" << std::endl;

    std::cout << "\x1b[1;37m\n== List ==\x1b[0m" << std::endl;
    std::cout << "\x1b[1;37m[" << easyFind(lst, 30) << "]\x1b[0m" << std::endl;
    std::cout << "\x1b[1;37m[" << easyFind(lst, 10) << "]\x1b[0m" << std::endl;
    std::cout << "\x1b[1;37m[" << easyFind(lst, 50) << "]\x1b[0m" << std::endl;
    std::cout << "\x1b[1;37m[" << easyFind(lst, 60) << "]\x1b[0m" << std::endl;

    return 0;
}
