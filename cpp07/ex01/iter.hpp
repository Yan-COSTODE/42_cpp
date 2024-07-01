#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>

template<typename T>
void iter(T *_ptr, size_t _length, void(*_func)(T))
{
    if (!_ptr)
        return;

    for (size_t i = 0; i < _length; i++)
    {
        _func(_ptr[i]);
    }
}

#endif
