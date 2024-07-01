#pragma once

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
int easyFind(T _container, int _toFind)
{
    typename T::iterator _it = std::find(_container.begin(), _container.end(), _toFind);

    if (_it != _container.end())
        return std::distance(_container.begin(), _it);

    return -1;
}

#endif
