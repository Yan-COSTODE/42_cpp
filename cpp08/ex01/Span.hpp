#pragma once

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <limits>

class Span {
    class SpanFullException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Span: Can't add a new number, it's already full";
        }
    };

    class SpanNotEnoughNumberException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Span: Not enough number to perform this";
        }
    };

    private:
        std::vector<int> span;
        unsigned int length;

    public:
        ~Span();
        Span();
        Span(unsigned int _length);
        Span(const Span& _other);
        Span& operator=(const Span& _other);
        void addNumber(int _value);
        void addNumber(std::vector<int>::iterator _begin, std::vector<int>::iterator _end);
        unsigned int shortestSpan();
        unsigned int longestSpan();
};

#endif
