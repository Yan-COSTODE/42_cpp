#pragma once

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

typedef struct s_Data
{
    std::string str;
    int n;

    s_Data(std::string _str, int _n)
    {
        str = _str;
        n = _n;
    }
} Data;

class Serializer {
    private:
        ~Serializer();
        Serializer();
        Serializer(const Serializer& _other);
        Serializer& operator=(const Serializer& _other);

    public:
        static uintptr_t serialize(Data* _ptr);
        static Data* deserialize(uintptr_t _raw);
};

#endif
