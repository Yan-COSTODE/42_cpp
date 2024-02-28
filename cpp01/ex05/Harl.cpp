#include "Harl.hpp"

Harl::~Harl()
{
}

Harl::Harl()
{
}

void Harl::debug()
{
	std::cout << "\x1b[1;37mI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do\x1b[0m" << std::endl;
}

void Harl::info()
{
	std::cout << "\x1b[1;37mI cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!\x1b[0m" << std::endl;
}

void Harl::warning()
{
	std::cout << "\x1b[1;37mI think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month.\x1b[0m" << std::endl;
}


void Harl::error()
{
	std::cout << "\x1b[1;37mThis is unacceptable! I want to speak to the manager now.\x1b[0m" << std::endl;
}

void Harl::complain(std::string level)
{
	FunctionInfo _functionInfo[] = {
		{"DEBUG", debug},
		{"INFO", info},
		{"WARNING", warning},
		{"ERROR", error}
	};

	for (int i = 0; i < 4; i++)
	{
		if (_functionInfo[i].name == level)
		{
			_functionInfo[i].function();
			return;
		}
	}
	std::cout << "\x1b[1;31mHarl doesn't know this level\x1b[0m" << std::endl;
}
