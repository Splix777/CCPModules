/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:44:36 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:44:37 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "Zombie " << this->_name << " is born" << std::endl;
}

Zombie::~Zombie( void )
{
    std::cout << "Zombie " << this->_name << " is deader?" << std::endl;
}

void    Zombie::announce( void )
{
    std::cout << this->_name << ": : BraiiiiiiinnnzzzZ..." << std::endl;
}
