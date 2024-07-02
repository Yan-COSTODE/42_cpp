#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

int PmergeMe::IsValidNumber(std::string _number)
{
    if (_number.empty())
    {
        std::cerr << "\x1b[1;31mError: can't comprehend an empty number\x1b[0m" << std::endl;
        return -1;
    }

    if (_number[0] == '-')
    {
        std::cerr << "\x1b[1;31mError: can't comprehend a negative number => " << _number << "\x1b[0m" << std::endl;
        return -1;
    }

    std::stringstream _ss(_number);
    int _value;

    if (_ss >> _value)
    {
        if (_value < 0)
        {
            std::cerr << "\x1b[1;31mError: too large number => " << _number << "\x1b[0m" << std::endl;
            return -1;
        }

        return _value;
    }
    else
    {
        std::cerr << "\x1b[1;31mError: can't comprehend this number => " << _number << "\x1b[0m" << std::endl;
        return -1;
    }
}

void PmergeMe::Init(int _argc, char **_argv)
{
    clock_t _start, _end;

    InitVector(_argc, _argv);
    Display("Before: ");
    vData.clear();

    _start = clock();
    InitVector(_argc, _argv);
    SortVector(0, vData.size() - 1);
    _end = clock();
    vTime = (double)(_end - _start) / CLOCKS_PER_SEC * 1000.0;

    _start = clock();
    InitDeque(_argc, _argv);
    SortDeque(0, dData.size() - 1);
    _end = clock();
    dTime = (double)(_end - _start) / CLOCKS_PER_SEC * 1000.0;

    Display("After : ");
    DisplayTime();
}

void PmergeMe::Display(std::string _msg)
{
    if (vData.empty())
        return;

    std::cout << "\x1b[1;37m" << _msg;

    for(std::vector<unsigned int>::iterator it = vData.begin(); it != vData.end(); it++)
        std::cout << *it << " ";

    std::cout << "\x1b[0m" << std::endl;
}

void PmergeMe::DisplayTime()
{
    std::cout << "\x1b[1;37mTime to process a range of " << vData.size() <<" elements with std::vector : " << vTime << " ms" << std::endl;
    std::cout << "\x1b[1;37mTime to process a range of " << dData.size() <<" elements with std::deque  : " << dTime << " ms" << std::endl;
}

void PmergeMe::InitVector(int _argc, char **_argv)
{
    for (int i = 1; i < _argc; ++i)
    {
        int _value = IsValidNumber(_argv[i]);

        if (_value != -1)
            vData.push_back(_value);
        else
            return;
    }
}

void PmergeMe::InitDeque(int _argc, char **_argv)
{
    for (int i = 1; i < _argc; ++i)
    {
        int _value = IsValidNumber(_argv[i]);

        if (_value != -1)
            dData.push_back(_value);
        else
            return;
    }
}

void PmergeMe::SortVector(int _left, int _right)
{
    if (_left < _right)
    {
        int _mid = _left + (_right - _left) / 2;

        SortVector(_left, _mid);
        SortVector(_mid + 1, _right);

        if (_right - _left + 1 > 2)
        {
            std::vector<int> _tmp(_right - _left + 1);
            int i = _left;
            int j = _mid + 1;
            size_t k = 0;

            while (i <= _mid && j <= _right)
            {
                if (vData[i] <= vData[j])
                    _tmp[k++] = vData[i++];
                else
                    _tmp[k++] = vData[j++];
            }

            while (i <= _mid)
                _tmp[k++] = vData[i++];

            while (j <= _right)
                _tmp[k++] = vData[j++];

            for (k = 0; k < _tmp.size(); k++)
                vData[_left + k] = _tmp[k];
        }
        else
            InsertionVector(_left, _right);
    }
}

void PmergeMe::InsertionVector(int _left, int _right)
{
    for (int i = _left + 1; i <= _right; ++i)
    {
        unsigned int key = vData[i];
        int j = i - 1;

        while (j >= _left && vData[j] > key)
        {
            vData[j + 1] = vData[j];
            --j;
        }

        vData[j + 1] = key;
    }
}

void PmergeMe::SortDeque(int _left, int _right)
{
    if (_left < _right)
    {
        int _mid = _left + (_right - _left) / 2;

        SortVector(_left, _mid);
        SortVector(_mid + 1, _right);

        if (_right - _left + 1 > 2)
        {
            std::deque<int> _tmp(_right - _left + 1);
            int i = _left;
            int j = _mid + 1;
            size_t k = 0;

            while (i <= _mid && j <= _right)
            {
                if (dData[i] <= dData[j])
                    _tmp[k++] = dData[i++];
                else
                    _tmp[k++] = dData[j++];
            }

            while (i <= _mid)
                _tmp[k++] = dData[i++];

            while (j <= _right)
                _tmp[k++] = dData[j++];

            for (k = 0; k < _tmp.size(); k++)
                dData[_left + k] = _tmp[k];
        }
        else
            InsertionDeque(_left, _right);
    }
}

void PmergeMe::InsertionDeque(int _left, int _right)
{
    for (int i = _left + 1; i <= _right; ++i)
    {
        unsigned int key = dData[i];
        int j = i - 1;

        while (j >= _left && dData[j] > key)
        {
            dData[j + 1] = dData[j];
            --j;
        }

        dData[j + 1] = key;
    }
}