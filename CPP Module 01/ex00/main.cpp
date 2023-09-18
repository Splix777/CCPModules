/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:44:42 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/15 18:22:21 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    {
        Zombie("Stack");
    }
    Zombie *zombie;

    zombie = newZombie("Bob");
    zombie->announce();
    delete zombie;
    randomChump("Random Zombie");
    return (0);
}
