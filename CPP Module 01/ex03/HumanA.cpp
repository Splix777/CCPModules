/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:49:02 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:50:11 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
    std::cout << this->_name << " was born" << std::endl;
    std::cout << this->_name << " has a " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << this->_name << " died" << std::endl;
}

void    HumanA::attack()
{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
