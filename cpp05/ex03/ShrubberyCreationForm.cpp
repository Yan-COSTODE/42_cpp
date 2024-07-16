#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm()
{
	const_cast<std::string&>(target) = "target";
	const_cast<std::string&>(name) = "Shrubbery Creation";
	status = false;
	const_cast<int&>(gradeSign) = 145;
	const_cast<int&>(gradeExec) = 137;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_target)
{
    const_cast<std::string&>(target) = _target;
    const_cast<std::string&>(name) = "Shrubbery Creation";
    status = false;
    const_cast<int&>(gradeSign) = 145;
    const_cast<int&>(gradeExec) = 137;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &_other) : AForm(_other)
{
	*this = _other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &_other)
{
	const_cast<std::string&>(target) = _other.target;
	const_cast<std::string&>(name) = _other.name;
	status = _other.status;
	const_cast<int&>(gradeSign) = _other.gradeSign;
	const_cast<int&>(gradeExec) = _other.gradeExec;
	return *this;
}

void ShrubberyCreationForm::executeAction()
{
	std::string _filename = target + "_shrubbery";
	std::ofstream outputFile(_filename.c_str());
	std::string tree;

	tree = "";
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			switch (i) {
				case 0: tree += "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
					break;
				case 1: tree +=	"⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⡰⡇⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀";
					break;
				case 2: tree +=	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⢾⠇⠨⡦⠀⠂⠀⠀⠀⠀⠀⠀⠀";
					break;
				case 3: tree +=	"⠀⠀⠀⠀⠀⠀⠀⡀⠀⢈⣹⠜⠻⢾⠃⠀⠀⠀⠀⠀⠀⠀⠀";
					break;
				case 4: tree +=	"⠀⠀⠀⠀⠀⠀⠀⠁⢠⣿⡵⠾⣻⣶⠿⠦⠀⠀⠀⠀⠀⠀⠀";
					break;
				case 5: tree +=	"⠀⠀⠀⠀⠀⢀⠀⢀⣠⣮⣦⡶⠻⠛⢶⣄⡀⠁⠀⠀⠀⠀⠀";
					break;
				case 6: tree +=	"⠀⠀⠀⠀⠀⠁⣠⣾⣵⣾⣾⠟⡙⠟⠿⣍⡉⠀⠀⠆⠀⠀⠀";
					break;
				case 7: tree +=	"⠀⠀⠰⠀⠀⠄⣠⣶⣾⣭⡶⠟⠻⣶⡰⣜⣳⣦⣄⠀⡀⠀⠀";
					break;
				case 8: tree +=	"⠀⠀⠀⠀⢀⣠⣴⣿⣋⡴⣪⠎⣄⡙⠻⠿⣯⣉⠉⠀⠀⠀⠀";
					break;
				case 9: tree +=	"⠀⠀⠂⠀⢀⣉⡭⢿⡛⣛⣵⠎⠀⠙⢾⣶⣦⣭⣷⣦⠐⠀⠀";
					break;
				case 10: tree +=	"⠀⠀⠀⢈⣙⣿⡿⠿⠟⣋⢅⡄⡄⡐⣄⢤⣉⠷⢦⣄⣀⠠⠀";
					break;
				case 11: tree +=	"⠀⠐⠾⠿⢽⣷⡶⠶⡿⣓⣭⣾⣿⢷⣬⣓⢿⠿⠿⣯⣉⣁⠀";
					break;
				case 12: tree +=	"⠀⠀⠀⠀⠉⠉⠉⠛⠛⠉⢀⣿⢿⡀⠙⠋⠓⠿⠿⠏⠉⠉⠀";
					break;
				case 13: tree +=	"⠀⠀⠀⠀⠀⠀⠀⠠⠤⠶⠾⢿⡯⠷⠶⠤⠄⠀⠀⠀⠀⠀⠀";
					break;
			}
		}
		tree += "\n";
	}
	outputFile << tree;
	outputFile.close();
}