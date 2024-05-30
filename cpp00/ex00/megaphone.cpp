#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "\x1b[1;37m* LOUD AND UNBEARABLE FEEDBACK NOISE *\x1b[0m" << std::endl;
	else
	{
		std::cout << "\x1b[1;37m";
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				argv[i][j] = std::toupper(argv[i][j]);
			std::cout << argv[i];
		}
		std::cout << "\x1b[0m" << std::endl;
	}
}