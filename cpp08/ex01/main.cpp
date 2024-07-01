#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(6);
    std::vector<int> vec;
    vec.push_back(6);
    vec.push_back(3);
    vec.push_back(17);
    vec.push_back(9);
    vec.push_back(11);
    sp.addNumber(14);
    sp.addNumber(vec.begin(), vec.end());

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}
