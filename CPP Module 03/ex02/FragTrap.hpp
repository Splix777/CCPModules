/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:55:42 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:55:42 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ClapTrap; // Forward declaration

class FragTrap : public ClapTrap
{
public:
    // Constructors & Destructors
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap const &copy);
    ~FragTrap();
    // Actions
    void attack(const std::string &target);
    void highFivesGuys(void);
    // Operator Overloads
    FragTrap &operator=(const FragTrap &copy);
};

#endif // FragTrap_HPP
