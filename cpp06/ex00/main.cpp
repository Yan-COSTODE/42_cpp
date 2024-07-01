#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "\x1b[1;31mWrong Number Of Arguments.\x1b[0m" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);
}