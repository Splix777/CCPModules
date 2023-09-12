/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:55:17 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:55:18 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("NPC")
{
    this->_HitPoints = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 20;
    this->_MaxHitPoints = 100;
    this->_MaxEnergyPoints = 50;
    this->_MaxAttackDamage = 20;
    std::cout << "ScavTrap NPC Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
    this->_HitPoints = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 20;
    this->_MaxHitPoints = 100;
    this->_MaxEnergyPoints = 50;
    this->_MaxAttackDamage = 20;
    this->_Name = name;
    std::cout << name << " ScavTrap was created. Ready for Battle!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
    *this = copy;
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->_Name << " ScavTrap was destroyed. Get pwned!" << std::endl;
}

ScavTrap    &ScavTrap::operator=(ScavTrap const &copy)
{
    if (this == &copy)
        return (*this);
    this->_Name = copy._Name;
    this->_HitPoints = copy._HitPoints;
    this->_EnergyPoints = copy._EnergyPoints;
    this->_AttackDamage = copy._AttackDamage;
    std::cout << "ScavTrap Assignment Operator called" << std::endl;
    return (*this);
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_EnergyPoints < 1)
    {
        std::cout << this->_Name << " does not have enough energy points to attack!" << std::endl;
        return ;
    }
    if (this->_HitPoints < 1)
    {
        std::cout << this->_Name << " is dead. How tf would he attack?" << std::endl;
        return ;
    }
    std::cout << this->_Name << " attacks " << target << ", kawabonga yippycayye mf! With " << this->_AttackDamage << " points of damage!" << std::endl;
    this->_EnergyPoints--;
    std::cout << this->_Name << " has " << this->getEP() << " energy left!" << std::endl;
}

void ScavTrap::guardGate()
{
    if (this->getHP() < 1)
        std::cout << this->_Name << " is dead. He cant guard the gate!" << std::endl;
    else
        std::cout << this->_Name << " is now in Gate Keeper mode!" << std::endl;
}
