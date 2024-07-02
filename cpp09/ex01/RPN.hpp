#pragma once

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <queue>
#include <stack>
#include <sstream>

class RPN {
    private:
        std::stack<int> values;

    public:
        ~RPN();
        RPN();
        RPN(const RPN& _other);
        RPN& operator=(const RPN& _other);
        void Calculate(std::string _prompt);
        void Execute(char _operator);
};

#endif
