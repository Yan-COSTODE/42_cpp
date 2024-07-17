#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array {
    private:
        T* array;
        size_t length;

    public:
        ~Array()
        {
            delete[] array;
        }

        Array()
        {
            array = new T[0]();
            length = 0;
        }

        Array(unsigned int _n)
        {
            array = new T[_n]();
            length = _n;

            for (unsigned int i = 0; i < _n; ++i)
                array[i] = T();
        }

        Array(const Array<T>& _other) {
            *this = _other;
        }

        Array& operator=(const Array<T>& _other)
        {
            length = _other.length;

            if (_other.length == 0)
                return *this;

            array = new T[length]();

            for (unsigned int i = 0; i < _other.length; ++i)
                array[i] = _other.array[i];

            return *this;
        }

        T& operator[](unsigned int _index)
        {
            if (_index >= length)
                throw std::out_of_range("Index out of bounds");

            return array[_index];
        }

        size_t size()
        {
            return length;
        }
};

#endif
