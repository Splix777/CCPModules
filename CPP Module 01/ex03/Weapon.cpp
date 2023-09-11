#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
    std::cout << name << " was created" << std::endl;
    this->_type = name;
}

Weapon::~Weapon()
{
    std::cout << this->_type << " was destroyed" << std::endl;
}

const std::string&  Weapon::getType(void)
{
    return (this->_type);
}

void    Weapon::setType(std::string type)
{
    std::cout << this->_type << " was dropped, now holding a " << type << std::endl;
    this->_type = type;
}

