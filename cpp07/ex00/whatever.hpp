#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T& _a, T& _b)
{
    T _tmp;

    _tmp = _a;
    _a = _b;
    _b = _tmp;
}

template<typename T>
T min(T& _a, T& _b)
{
    return _a >= _b ? _b : _a;
}

template<typename T>
T max(T& _a, T& _b)
{
    return _a <= _b ? _b : _a;
}

#endif
