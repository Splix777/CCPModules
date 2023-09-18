/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:44:25 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/15 18:19:59 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    if (name.empty())
        name = "Default Zombie";
    Zombie  *zombie;

    zombie = new Zombie(name);
    if (zombie == NULL)
        return (NULL);
    return (zombie);
}
