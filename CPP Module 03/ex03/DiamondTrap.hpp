/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:56:11 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:56:12 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
    // Constructors and destructors
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap const &copy);
    ~DiamondTrap();
    // Actions
    void whoAmI( void );
    void attack(const std::string &target);
    // Operator Overloads
    DiamondTrap &operator=(const DiamondTrap &copy);

private:
    std::string _Name;
};

#endif