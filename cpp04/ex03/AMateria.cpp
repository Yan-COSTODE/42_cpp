#include "AMateria.hpp"

AMateria::~AMateria()
{
}

AMateria::AMateria()
{
	type = "materia";
}

AMateria::AMateria(std::string const &_type)
{
	type = _type;
}

AMateria::AMateria(const AMateria &_other)
{
	type = _other.type;
}

AMateria &AMateria::operator=(const AMateria &_other)
{
	type = _other.type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &_target)
{
	std::cout << "\x1b[1;32m* no materia to use on " << _target.getName() << " *\x1b[0m" << std::endl;
}
