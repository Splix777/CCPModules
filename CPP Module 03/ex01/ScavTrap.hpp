/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:55:20 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:55:21 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ClapTrap; // Forward declaration

class ScavTrap : public ClapTrap
{
    public:
        // Constructors & Destructors
        ScavTrap();
        ScavTrap(std::string const &name);
        ScavTrap(ScavTrap const &copy);
        ~ScavTrap();
        // Operator Overloads
        ScavTrap    &operator=(const ScavTrap &copy);
        // Actions
        void    attack(const std::string &target);
        void    guardGate();
};

#endif // SCAVTRAP_HPP
