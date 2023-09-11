#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "Zombie " << this->_name << " is born" << std::endl;
}

Zombie::Zombie( void )
{
    this->_name = "(null)";
    std::cout << "Zombie " << this->_name << " is born" << std::endl;
}

Zombie::~Zombie( void )
{
    std::cout << "Zombie " << this->_name << " is deader?" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::giveName(std::string name)
{
    this->_name = name;
}