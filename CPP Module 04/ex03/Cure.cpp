#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << _type << " constructed\n";
}

Cure::~Cure()
{
	std::cout << _type << " destroyed\n";
}

Cure *Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}