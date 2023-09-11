#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal()
{
    std::cout << "A random Cat was born!" << std::endl;
    _type = "Cat";
}

Cat::~Cat()
{
    std::cout << "The Cat is sleeping with the fish!" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    this->_type = copy._type;
    std::cout << "A Cat was copied!" << std::endl;

}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
        this->_type = copy._type;
    std::cout << "A Cat was assigned!" << std::endl;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "I'm a " << this->getType() << ", MEOW!!" << std::endl;
}