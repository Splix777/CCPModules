/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:01 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:01 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "A new WrongAnimal was born!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
    *this = copy;
    std::cout << "A new WrongAnimal was born!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "The WrongAnimal is sleeping with the fish!" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(WrongAnimal const &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    std::cout << "WrongAnimal has been cloned!" << std::endl;
    return (*this);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "Imaginary WrongAnimals dont make sounds!" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}