/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:07 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:07 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "A random WrongCat was born!" << std::endl;
    _type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "The WrongCat is sleeping with the fish!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    this->_type = copy._type;
    std::cout << "A WrongCat was copied!" << std::endl;

}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    if (this != &copy)
        this->_type = copy._type;
    std::cout << "A WrongCat was assigned!" << std::endl;
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << "I'm a " << this->getType() << ", MEOW!!" << std::endl;
}