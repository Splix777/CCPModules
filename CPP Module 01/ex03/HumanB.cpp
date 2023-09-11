#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
    std::cout << this->_name << " was born" << std::endl;
    std::cout << this->_name << " has no weapon" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << this->_name << " has died" << std::endl;
}

void    HumanB::attack(void)
{
    if (_weapon)
        std::cout << this->_name << " attack with " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " attacks with his hands" << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon)
{
    std::cout << this->_name << " has a picked up" << weapon.getType() << std::endl;
    this->_weapon = &weapon;
}
