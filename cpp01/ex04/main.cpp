#include <iostream>
#include "FileManager.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "\x1b[1;31mWrong numbers of parameters\x1b[0m" << std::endl;
		return 1;
	}

	FileManager _fileManager = FileManager(argv[1]);
	_fileManager.Replace(argv[2], argv[3]);
	return (0);
}