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
		std::cout << "\x1b[1;31mCan't open input file\x1b[0m" << std::endl;
		return;
	}

	std::ofstream _output(fileNameTreated.c_str());
	if (!_output.is_open())
	{
		std::cout << "\x1b[1;31mCan't create output file\x1b[0m" << std::endl;
		_input.close();
		return;
	}

	std::string line;
	while (std::getline(_input, line)) {
		size_t _pos = 0;
		while ((_pos = line.find(_find, _pos)) != std::string::npos) {
			line.replace(_pos, _replacer.length(), _replacer);
			_pos += _replacer.length();
		}
		_output << line << std::endl;
	}

	_input.close();
	_output.close();
}
