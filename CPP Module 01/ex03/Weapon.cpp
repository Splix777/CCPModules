/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:50:34 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:51:33 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
    std::cout << name << " was created" << std::endl;
    this->_type = name;
}

Weapon::~Weapon()
{
    std::cout << this->_type << " was destroyed" << std::endl;
}

const std::string&  Weapon::getType(void)
{
    return (this->_type);
}

void    Weapon::setType(std::string type)
{
    std::cout << this->_type << " was dropped, now holding a " << type << std::endl;
    this->_type = type;
}

