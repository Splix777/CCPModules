/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:33 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:33 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "AAnimal.hpp"

Cat::Cat() : AAnimal()
{
    std::cout << "A random Cat was born!" << std::endl;
    _type = "Cat";
    this->_brain = new Brain();
    if (this->_brain == NULL)
        std::cout << "Error: Memory allocation failed!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "The Cat is sleeping with the fish!" << std::endl;
    delete (this->_brain);
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
    std::cout << "A Cat was copied!" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "A Cat was assigned!" << std::endl;
    if (this == &copy)
        return (*this);
    this->_type = copy._type;
    this->_brain = new Brain();
    if (this->_brain == NULL)
        std::cout << "Error: Memory allocation failed!" << std::endl;
    *this->_brain = *copy._brain;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "I'm a " << this->getType() << ", MEOW!!" << std::endl;
}

void    Cat::getIdeas(void) const
{
    std::cout << "I'm a " << this->getType() << "! I have these ideas!" << std::endl;
    for(int i = 0; i < 100; i++)
        std::cout << "Idea " << i << ": " << this->_brain->getIdeas(i) << std::endl;
}

void    Cat::setIdeas(std::string idea, int i)
{
    this->_brain->setIdeas(i, idea);
}