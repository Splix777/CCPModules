/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:56:09 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:56:09 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("NPC_clap_name")
{
    std::cout << "NPC DiamondTrap Constructor called" << std::endl;
    _HitPoints = FragTrap::_HitPoints;
    _EnergyPoints = ScavTrap::_EnergyPoints;
    _AttackDamage = FragTrap::_AttackDamage;
    _MaxHitPoints = FragTrap::_MaxHitPoints;
    _MaxEnergyPoints = ScavTrap::_MaxEnergyPoints;
    _MaxAttackDamage = FragTrap::_MaxAttackDamage;
    _Name = "NPC";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
    std::cout << name << " DiamondTrap was created. Ready for Battle!" << std::endl;
    _HitPoints = FragTrap::_HitPoints;
    _EnergyPoints = ScavTrap::_EnergyPoints;
    _AttackDamage = FragTrap::_AttackDamage;
    _MaxHitPoints = FragTrap::_MaxHitPoints;
    _MaxEnergyPoints = ScavTrap::_MaxEnergyPoints;
    _MaxAttackDamage = FragTrap::_MaxAttackDamage;
    _Name = name;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << _Name << " DiamondTrap was destroyed. He fought valiantly" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy),  FragTrap(copy), ScavTrap(copy)
{
    *this = copy;
    std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &copy)
{
    if (this == &copy)
        return (*this);
    _Name = copy._Name;
    _HitPoints = copy._HitPoints;
    _EnergyPoints = copy._EnergyPoints;
    _AttackDamage = copy._AttackDamage;
    _MaxHitPoints = copy._MaxHitPoints;
    _MaxEnergyPoints = copy._MaxEnergyPoints;
    _MaxAttackDamage = copy._MaxAttackDamage;
    return (*this);
    std::cout << _Name << " DiamondTrap overload operator was called!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << this->_Name << ", and my ClapTrap name is " << ClapTrap::_Name <<std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    this->ScavTrap::attack(target);
}