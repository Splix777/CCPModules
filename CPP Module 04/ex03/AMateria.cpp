#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Abstract materia has beed created" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "Abstract materia has beed constructed" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Abstract materia has beed destroyed" << std::endl;
}

AMateria::AMateria(AMateria const &copy) : _type(copy._type)
{
	std::cout << "Abstract materia has beed constructed from a copy" << std::endl;
}

std::string const & AMateria::getType() const
{
	return(_type);
}

void AMateria::use(ICharacter &target)
{
	(void) target;
}