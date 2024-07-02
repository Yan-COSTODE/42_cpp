#pragma once

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>
#include <iomanip>
#include <limits>

class BitcoinExchange {
    private:
        std::map<std::string, float> data;

    public:
        ~BitcoinExchange();
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& _other);
        BitcoinExchange& operator=(const BitcoinExchange& _other);
        void InitData();
        void GetData(std::string _fileName);
        void ParseFile(std::string _fileName);
        void ParseLine(std::string _line, std::string _separator);
        std::string GetSeparator(std::string _line, std::string _first, std::string _second);
        bool IsLeapYear(int _year);
        bool IsValidDate(std::string _date);
        bool IsValidDate(int _year, int _month, int _day);
        float GetNearestMult(std::string _date);
        std::string GetPrecedentDay(std::string _date);
};

#endif
