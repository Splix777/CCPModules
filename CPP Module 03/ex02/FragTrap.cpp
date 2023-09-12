/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:55:38 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:55:39 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("NPC")
{
    this->_HitPoints = 100;
    this->_EnergyPoints = 100;
    this->_AttackDamage = 30;
    this->_MaxHitPoints = 100;
    this->_MaxEnergyPoints = 100;
    this->_MaxAttackDamage = 30;
    std::cout << "NPC FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_HitPoints = 100;
    this->_EnergyPoints = 100;
    this->_AttackDamage = 30;
    this->_MaxHitPoints = 100;
    this->_MaxEnergyPoints = 100;
    this->_MaxAttackDamage = 30;
    this->_Name = name;
    std::cout << name << " FragTrap was created. Ready for Battle!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
    *this = copy;
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << this->_Name << " FragTrap was destroyed. Sleep with the fishies!" << std::endl;
}

void    FragTrap::attack(const std::string &target)
{
    if (this->_EnergyPoints < 1)
    {
        std::cout << this->_Name << " does not have enough energy points to attack!" << std::endl;
        return;
    }
    if (this->_HitPoints < 1)
    {
        std::cout << this->_Name << " is dead. He cant attack, only God can judge him now!" << std::endl;
        return;
    }
    std::cout << this->_Name << " attacks " << target << ", pew pew pew! DIE!! " << this->_AttackDamage << " points of damage!" << std::endl;
    this->_EnergyPoints--;
    std::cout << this->_Name << " has " << this->getEP() << " energy left!" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    if (this->_EnergyPoints < 1)
        std::cout << this->_Name << " has no POWAAA! Can't High Five!" << std::endl;
    if (this->_HitPoints < 1)
        std::cout << this->_Name << " is dead bro! Can't High Five!" << std::endl;
    else
        std::cout << this->_Name << " High Fived the Guys!" << std::endl;
}

FragTrap    &FragTrap::operator=(FragTrap const &copy)
{
    if (this == &copy)
        return (*this);
    this->_Name = copy._Name;
    this->_HitPoints = copy._HitPoints;
    this->_EnergyPoints = copy._EnergyPoints;
    this->_AttackDamage = copy._AttackDamage;
    this->_MaxHitPoints = copy._MaxHitPoints;
    this->_MaxEnergyPoints = copy._MaxEnergyPoints;
    this->_MaxAttackDamage = copy._MaxAttackDamage;
    std::cout << this->_Name << " FragTrap overload operator was called!" << std::endl;
    return (*this);
}