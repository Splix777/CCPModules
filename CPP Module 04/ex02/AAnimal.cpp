#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Animal")
{
    std::cout << "A new animal was born!" << std::endl;
}

AAnimal::AAnimal(AAnimal const &copy)
{
    std::cout << "A new animal was born!" << std::endl;
    *this = copy;
}

AAnimal::~AAnimal()
{
    std::cout << "The animal is sleeping with the fish!" << std::endl;
}

AAnimal  &AAnimal::operator=(AAnimal const &copy)
{
    std::cout << "Animal has been cloned!" << std::endl;
    this->_type = copy._type;
    return (*this);
}

void    AAnimal::makeSound(void) const
{
    std::cout << "Imaginary animals dont make sounds!" << std::endl;
}

std::string AAnimal::getType(void) const
{
    return (this->_type);
}