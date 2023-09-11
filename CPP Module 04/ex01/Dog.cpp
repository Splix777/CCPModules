#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal()
{
    std::cout << "A random Dog was born!" << std::endl;
    _type = "Dog";
    this->_brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "The Dog is sleeping with the fish!" << std::endl;
    delete this->_brain;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    this->_type = copy._type;
    this->_brain = new Brain(*copy._brain);
    std::cout << "A Dog was copied!" << std::endl;

}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
        delete this->_brain;
        this->_brain = new Brain(*copy._brain);
    }
    std::cout << "A Dog was assigned!" << std::endl;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "I'm a " << this->getType() << ", Woof!!" << std::endl;
}

Brain* Dog::getBrain()
{
	return (this->_brain);
}