/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:56:57 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:56:58 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal()
{
    std::cout << "A random Dog was born!" << std::endl;
    _type = "Dog";
}

Dog::~Dog()
{
    std::cout << "The Dog is sleeping with the fish!" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "A Dog was copied!" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
        this->_type = copy._type;
    std::cout << "A Dog was assigned!" << std::endl;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "I'm a " << this->getType() << ", WOOF!!" << std::endl;
}