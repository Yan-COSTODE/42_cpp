#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cmath>

class ScalarConverter {
	template<typename T>
	struct Converted {
		bool status;
		std::string brut;
		T data;

		Converted(bool _status = false, T _data = 0, std::string _brut = "")
		{
			status = _status;
			data = _data;
			brut = _brut;
		}
	};

	struct Data {
		Converted<char> c;
		Converted<int> i;
		Converted<float> f;
		Converted<double> d;
		size_t precision;

		Data()
		{
			c = Converted<char>();
			i = Converted<int>();
			f = Converted<float>();
			d = Converted<double>();
			precision = 1;
		}
	};

	private:
		ScalarConverter();
		static bool atod(const std::string& _str, double& _result, double _min, double _max);
		static bool convertFromBrut(Data& _data, const std::string& _str);
		static bool convertFromChar(Data& _data, const std::string& _str);
		static bool convertFromInt(Data& _data, const std::string& _str);
		static bool convertFromFloat(Data& _data, const std::string& _str);
		static bool convertFromDouble(Data& _data, const std::string& _str);
		static int getPrecision(const std::string& _str);
		static void showConvert(Data& _data);
		static bool parseArgs(const std::string& _str);

	public:
		static void convert(const std::string& _str);
};

#endif
