#include "Ice.hpp"

Ice::~Ice()
{
}

Ice::Ice() : AMateria()
{
	type = "ice";
}

Ice::Ice(std::string const &_type) : AMateria(_type)
{
}

Ice::Ice(const Ice &_other)
{
	*this = _other;
}

Ice &Ice::operator=(const Ice &_other)
{
	AMateria::operator=(_other);
	return *this;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &_target)
{
	std::cout << "\x1b[1;36m* shoots an ice bolt at " << _target.getName() << " *\x1b[0m" << std::endl;
}
