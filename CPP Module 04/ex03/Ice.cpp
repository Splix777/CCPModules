#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << _type << " constructed\n";
}

Ice::~Ice()
{
	std::cout << _type << " destroyed\n";
}

Ice *Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}