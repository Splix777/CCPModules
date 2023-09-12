/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:38 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:38 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "AAnimal.hpp"

Dog::Dog() : AAnimal()
{
    std::cout << "A random Dog was born!" << std::endl;
    _type = "Dog";
    this->_brain = new Brain();
    if (this->_brain == NULL)
        std::cout << "Error: Memory alloDogion failed!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "The Dog is sleeping with the fish!" << std::endl;
    delete (this->_brain);
}

Dog::Dog(const Dog &copy) : AAnimal(copy)
{
    std::cout << "A Dog was copied!" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "A Dog was assigned!" << std::endl;
    if (this == &copy)
        return (*this);
    this->_type = copy._type;
    this->_brain = new Brain();
    if (this->_brain == NULL)
        std::cout << "Error: Memory alloDogion failed!" << std::endl;
    *this->_brain = *copy._brain;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "I'm a " << this->getType() << ", WOOF!!" << std::endl;
}

void    Dog::getIdeas(void) const
{
    std::cout << "I'm a " << this->getType() << "! I have these ideas!" << std::endl;
    for(int i = 0; i < 100; i++)
        std::cout << "Idea " << i << ": " << this->_brain->getIdeas(i) << std::endl;
}

void    Dog::setIdeas(std::string idea, int i)
{
    this->_brain->setIdeas(i, idea);
}