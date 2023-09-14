/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:54:47 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/14 12:40:16 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap NPC;
    std::cout << std::endl;
    ClapTrap Bobby("Bobby");
    std::cout << std::endl;

    Bobby.attack("NPC");
    std::cout << std::endl;
    NPC.takeDamage(Bobby.getAD());
    std::cout << std::endl;
    Bobby.takeDamage(9);
    std::cout << std::endl;
    Bobby.beRepaired(100);
    Bobby.attack("NPC");
    Bobby.attack("NPC");
    Bobby.attack("NPC");
    Bobby.attack("NPC");
    Bobby.attack("NPC");
    Bobby.attack("NPC");
    Bobby.attack("NPC");
    // Bobby.attack("NPC");

    std::cout << std::endl;
    Bobby.takeDamage(100);
    std::cout << std::endl;
    Bobby.beRepaired(100);
    std::cout << std::endl;
    Bobby.attack("NPC");
    std::cout << std::endl;

    ClapTrap Jimmy(Bobby);
    std::cout << std::endl;
    ClapTrap Timmy = Jimmy;
    std::cout << std::endl;

    return (0);
}