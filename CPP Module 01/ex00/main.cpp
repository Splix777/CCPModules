/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:44:42 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 16:41:18 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    {
        Zombie("Stack");
    }
    Zombie *zombie;

    zombie = newZombie("Zombie1");
    zombie->announce();
    delete zombie;
    randomChump("Random Zombie");
    return (0);
}
