#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
	private:
		static void debug(void);
		static void info(void);
		static void warning(void);
		static void error(void);

	public:
		~Harl();
		Harl();
		void complain(std::string _level);
};

#endif
