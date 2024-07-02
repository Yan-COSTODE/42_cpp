#pragma once

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <sstream>

class PmergeMe {
    private:
        std::vector<unsigned int> vData;
        std::deque<unsigned int> dData;
        double vTime;
    double dTime;

    private:
        int IsValidNumber(std::string _number);
        void Display(std::string _msg);
        void DisplayTime();
        void SortVector(int _left, int _right);
        void SortDeque(int _left, int _right);
        void InsertionVector(int _left, int _right);
        void InsertionDeque(int _left, int _right);
        void InitVector(int _argc, char **_argv);
        void InitDeque(int _argc, char **_argv);

    public:
        PmergeMe();
        void Init(int _argc, char** _argv);
};

#endif
