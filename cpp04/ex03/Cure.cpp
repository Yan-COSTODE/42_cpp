#include "Cure.hpp"

Cure::~Cure()
{
}

Cure::Cure() : AMateria()
{
	type = "cure";
}

Cure::Cure(std::string const &_type) : AMateria(_type)
{
}

Cure::Cure(const Cure &_other)
{
	*this = _other;
}

Cure &Cure::operator=(const Cure &_other)
{
	AMateria::operator=(_other);
	return *this;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &_target)
{
	std::cout << "\x1b[1;32m* heals " << _target.getName() << "'s wounds *\x1b[0m" << std::endl;
}
