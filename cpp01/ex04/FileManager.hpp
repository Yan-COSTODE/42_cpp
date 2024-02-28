#pragma once
#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>
#include <fstream>
#include <iostream>

class FileManager {
	private:
		std::string fileName;
		std::string fileNameTreated;

	public:
		~FileManager();
		FileManager();
		FileManager(std::string _fileName);
		void Replace(std::string _find, std::string _replacer);
};

#endif
