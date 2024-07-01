#include "Serializer.hpp"

Serializer::~Serializer()
{
}

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &_other)
{
    *this = _other;
}

Serializer &Serializer::operator=(const Serializer &_other) {
    (void)_other;
    return *this;
}

uintptr_t Serializer::serialize(Data* _ptr)
{
    return reinterpret_cast<uintptr_t>(_ptr);
}

Data *Serializer::deserialize(uintptr_t _raw)
{
    return reinterpret_cast<Data *>(_raw);
}
