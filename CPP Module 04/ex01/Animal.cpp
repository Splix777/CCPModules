/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:57:25 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:57:26 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "A new animal was born!" << std::endl;
}

Animal::Animal(Animal const &copy)
{
    *this = copy;
    std::cout << "A new animal was born!" << std::endl;
}

Animal::~Animal()
{
    std::cout << "The animal is sleeping with the fish!" << std::endl;
}

Animal  &Animal::operator=(Animal const &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    std::cout << "Animal has been cloned!" << std::endl;
    return (*this);
}

void    Animal::makeSound(void) const
{
    std::cout << "Imaginary animals dont make sounds!" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->_type);
}