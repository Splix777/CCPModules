#include "Floor.hpp"

Floor::Floor() : _nbItems(0)
{
    std::cout << "Floor created!" << std::endl;
    for (int i = 0; i < MAX_FLOOR_ITEMS; i++)
    {
        _inventory[i] = NULL;
    }
}

Floor::~Floor()
{
    std::cout << "Floor destroyed!" << std::endl;
    for (int i = 0; i < MAX_FLOOR_ITEMS; i++)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
}

void    Floor::dropItem(AMateria *m, ICharacter &target)
{
    
    if (_nbItems < MAX_FLOOR_ITEMS)
    {
        for(int i = 0; i < MAX_FLOOR_ITEMS; i++)
        {
            if (!_inventory[i])
            {
                _inventory[i] = m;
                _nbItems++;
                std::cout << target.getName() << " Dropped " << m->getType() << " on the floor!" << std::endl;
                return ;
            }
        }
    }
    else
    {
        std::cout << "The floor is full! Can't drop any more Materia! Materia was destroyed!" << std::endl;
        delete m;
    }
}

void    Floor::pickUpItem(std::string const &itemName, ICharacter &target)
{
    for(int i = 0; i < MAX_FLOOR_ITEMS; i++)
    {
        if (_inventory[i] && _inventory[i]->getType() == itemName)
        {
            std::cout << "Picked up " << itemName << " from the floor!" << std::endl;
            target.equip(_inventory[i]);
            _inventory[i] = NULL;
            _nbItems--;
            return ;
        }
    }
    std::cout << "No " << itemName << " on the floor!" << std::endl;
}

int     Floor::getNbItems() const
{
    return (_nbItems);
}

void    Floor::printInventory() const
{
    for (int i = 0; i < MAX_FLOOR_ITEMS; i++)
    {
        if (_inventory[i])
            std::cout << _inventory[i]->getType() << std::endl;
    }
}
