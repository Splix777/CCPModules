#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Materia source was created" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			this->_inventory[i] = (copy._inventory[i])->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << "Materia source was created from copy" << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & copy)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (copy._inventory[i])
			this->_inventory[i] = (copy._inventory[i])->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << "Materia source was created from operator overload" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	std::cout << "Materia source was destroyed" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;

	if (!m)
	{
		std::cout << "Can't learn NULL Materia, you silly goose!" << std::endl;
		return ;
	}
	while (i < 4 && this->_inventory[i])
	{
		if (_inventory[i]->getType() == m->getType())
		{
			std::cout << "Materia " << m->getType() << " already learned!" << std::endl;
			delete m;
			return ;
		}
		i++;
	}
	if (i > 3)
	{
		std::cout << "Can't learn more than 4 Materia!" << std::endl;
		delete m;
		return ;
	}
	this->_inventory[i] = m;
	std::cout << "Materia " << m->getType() << " learned!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	int i = 0;

	while (i < 4 && this->_inventory[i] && this->_inventory[i]->getType() != type)
		i++;
	if (i > 3 || !(this->_inventory)[i])
	{
		std::cout << type << " materia does not exist!" << std::endl;
		return (NULL);
	}
	std::cout << "Materia " << type << " created!" << std::endl;
	return (this->_inventory[i]->clone());
}

void	MateriaSource::printInventory() const
{
	int i = 0;

	while (i < 4 && this->_inventory[i])
	{
		std::cout << "Materia " << i << ": " << this->_inventory[i]->getType() << std::endl;
		i++;
	}
}