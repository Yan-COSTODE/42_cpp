#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class ScalarConverter {
	template<typename T>
	struct Converted {
		bool status;
		T data;

		Converted(bool _status, T _data)
		{
			status = _status;
			data = _data;
		}
	};

	private:
		ScalarConverter();
		template<typename T>
		static void stringToNumeric(Converted<T>& _converted, const std::string& _str);

	public:
		static void convert(const std::string& _str);
};

#endif
