/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:55:45 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:55:45 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    // Create a ClapTrap
    ClapTrap clapTrap("ClapTrap");
    clapTrap.attack("Target 1");
    clapTrap.takeDamage(20);
    clapTrap.beRepaired(10);
    std::cout << "Current HP: " << clapTrap.getHP() << std::endl;
    std::cout << std::endl;

    // Create a ScavTrap
    ScavTrap scavTrap("Scavenger");
    scavTrap.attack("Target 2");
    scavTrap.guardGate();
    scavTrap.takeDamage(100);
    scavTrap.guardGate();
    std::cout << std::endl;

    // Create a FragTrap
    FragTrap fragTrap("Fragger");
    fragTrap.attack("Target 3");
    fragTrap.highFivesGuys();
    fragTrap.takeDamage(100);
    fragTrap.highFivesGuys();
    std::cout << std::endl;

    return 0;
}
