#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal()
{
    std::cout << "A random Cat was born!" << std::endl;
    _type = "Cat";
    this->_brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "The Cat is sleeping with the fish!" << std::endl;
    delete this->_brain;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    this->_type = copy._type;
    this->_brain = new Brain(*copy._brain);
    std::cout << "A Cat was copied!" << std::endl;

}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
        delete this->_brain;
        this->_brain = new Brain(*copy._brain);
    }
    std::cout << "A Cat was assigned!" << std::endl;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "I'm a " << this->getType() << ", MEOW!!" << std::endl;
}

Brain* Cat::getBrain()
{
	return (this->_brain);
}