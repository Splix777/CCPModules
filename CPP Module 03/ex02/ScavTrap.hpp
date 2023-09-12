/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:55:55 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:55:56 by fsalazar         ###   ########.fr       */
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
        // Actions
        void    attack(const std::string &target);
        void    guardGate();
        // Operator Overloads
        ScavTrap    &operator=(const ScavTrap &copy);
};

#endif // SCAVTRAP_HPP
