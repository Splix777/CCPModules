#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
	std::cout << _name << ": Just another boring day!" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << _name << ": My work here is done!" << std::endl;
}

std::string const &Character::getName() const
{
	return (_name);
}

Character::Character(Character const &copy) : _name(copy.getName() + "_copy")
{
	for(int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			(_inventory)[i] = (copy._inventory[i])->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << _name << " has been cloned!" << copy._name << ": I'm being cloned?!" << std::endl;
}

Character & Character::operator=(Character const &copy)
{
	// Name will remain the same since _name is a const
	for(int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (copy._inventory[i])
			_inventory[i] = (copy._inventory[i])->clone();
		else
			_inventory[i] = NULL;
	}
	return (*this);
}

void Character::equip(AMateria* m)
{
	int i = 0;

	if (!m)
	{
		std::cout << _name << " nothing to equip!" << std::endl;
		return ;
	}
	while (i < 4 && _inventory[i])
	{
		if (_inventory[i]->getType() == m->getType())
		{
			std::cout << _name << " already has " << m->getType() << " equiped!" << std::endl;
			delete m;
			return ;
		}
		i++;
	}
	if (i == 4)
	{
		std::cout << _name << ": inventory is full, can't equip " << m->getType() << std::endl;
		delete m;
		return ;
	}
	_inventory[i] = m;
	std::cout << _name << " equipped materia " << m->getType() << " in slot " << i + 1 << std::endl;
}

void Character::pickUpFromFloor(std::string const &type)
{
	_floor.pickUpItem(type, *this);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << this->_name << " that inventory slot does not exist! (" << idx << ")" << std::endl;
	else if (!(this->_inventory)[idx])
		std::cout << this->_name << " doesn't have a materia equiped at slot " << idx << std::endl;
	else
	{
		std::cout << this->_name << " unequipped " << (this->_inventory)[idx]->getType() << " at slot "<< idx << std::endl;
		_floor.dropItem((this->_inventory)[idx], *this);
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || (this->_inventory)[idx] == NULL)
	{
		std::cout << "No materia equiped at slot " << idx << std::endl;
		return ;
	}
	std::cout << this->getName() << ": ";
	((this->_inventory)[idx])->use(target);
}

// used to avoid leaks when using unequip with a deep copy character
AMateria	*Character::getMateria(int idx)
{
	return (this->_inventory)[idx];
}

void		Character::printInventory() const
{
	std::cout << this->_name << "'s inventory:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inventory)[i])
			std::cout << "Slot " << i << ": " << (this->_inventory)[i]->getType() << std::endl;
		else
			std::cout << "Slot " << i << ": empty" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Floor items: " << _floor.getNbItems() << std::endl;
	_floor.printInventory();
}
