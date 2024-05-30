#include "Harl.hpp"

int main()
{
	Harl _harl = Harl();

	_harl.complain("DEBUG");
	_harl.complain("INFO");
	_harl.complain("WARNING");
	_harl.complain("ERROR");
	_harl.complain("");
	_harl.complain("OUI");

}