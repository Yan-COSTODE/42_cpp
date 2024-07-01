#include "Serializer.hpp"
#include <iostream>

int main()
{
    uintptr_t _int;
    Data _data = Data("Data", 10);
    Data* _return;

    std::cout << "\x1b[1;37m-- Initial Data --\x1b[0m" << std::endl;
    std::cout << _data.str << ", " << _data.n << std::endl << std::endl;

    _int = Serializer::serialize(&_data);
    std::cout << "\x1b[1;37m-- Serialized Data --\x1b[0m" << std::endl;
    std::cout << _int << std::endl << std::endl;

    _return = Serializer::deserialize(_int);
    std::cout << "\x1b[1;37m-- Final Data --\x1b[0m" << std::endl;
    std::cout << _return->str << ", " << _return->n << std::endl;
}