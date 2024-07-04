#include "Span.hpp"

Span::~Span()
{
}

Span::Span()
{
    length = 0;
}

Span::Span(unsigned int _length)
{
    length = _length;
}

Span::Span(const Span &_other)
{
    *this = _other;
}

Span &Span::operator=(const Span &_other)
{
    length = _other.length;

    for (unsigned int i = 0; i < length; ++i)
        span[i] = _other.span[i];

    return *this;
}

void Span::addNumber(int _value)
{
    if (span.size() >= length)
        throw SpanFullException();

    span.push_back(_value);
}

void Span::addNumber(std::vector<int>::iterator _begin, std::vector<int>::iterator _end)
{
    for (std::vector<int>::iterator it = _begin; it != _end; ++it)
        addNumber(*it);
}

unsigned int Span::shortestSpan()
{
    if (span.size() < 2)
        throw SpanNotEnoughNumberException();

    unsigned int _shortest = std::numeric_limits<unsigned int>::max();
    std::vector<int> _sorted = span;
    std::sort(span.begin(), span.end());

    for (std::vector<int>::iterator it = _sorted.begin() + 1; it != _sorted.end(); ++it) {
        unsigned int diff = std::abs(*it - *(it - 1));

        if (diff < _shortest)
            _shortest = diff;
    }

    return _shortest;
}

unsigned int Span::longestSpan()
{
    if (span.size() < 2)
        throw SpanNotEnoughNumberException();

    int _max = *std::max_element(span.begin(), span.end());
    int _min = *std::min_element(span.begin(), span.end());

    return _max - _min;
}