#include "FileManager.hpp"

FileManager::~FileManager()
{
}

FileManager::FileManager()
{
	fileName = "fileName";
	fileNameTreated = fileName + ".replace";
}

FileManager::FileManager(std::string _fileName)
{
	fileName = _fileName;
	fileNameTreated = _fileName + ".replace";
}

void FileManager::Replace(std::string _find, std::string _replacer)
{
	std::ifstream _input(fileName.c_str());

	if (!_input.is_open())
	{
		std::cout << "\x1b[1;31mError: Can't open input file\x1b[0m" << std::endl;
		return;
	}

	std::ofstream _output(fileNameTreated.c_str());

	if (!_output.is_open())
	{
		std::cout << "\x1b[1;31Error: mCan't create output file\x1b[0m" << std::endl;
		_input.close();
		return;
	}

	std::string _line;

	while (std::getline(_input, _line))
	{
		size_t _pos = 0;

		if (!_find.empty())
		{
			while ((_pos = _line.find(_find, _pos)) != std::string::npos) {
				_line.erase(_pos, _find.length());
				_line.insert(_pos, _replacer);
				_pos += _replacer.length();
			}
		}

		_output << _line << std::endl;
	}

	_input.close();
	_output.close();
}
