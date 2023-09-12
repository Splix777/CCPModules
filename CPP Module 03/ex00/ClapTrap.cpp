/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:54:37 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:54:39 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("NPC")
{
    this->_HitPoints = 10;
    this->_EnergyPoints = 10;
    this->_AttackDamage = 0;
    this->_MaxHitPoints = 10;
    this->_MaxEnergyPoints = 10;
    this->_MaxAttackDamage = 0;
    std::cout << this->_Name << " ClapTrap was created. Ready for Battle!" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name) : _Name(name)
{
    this->_HitPoints = 10;
    this->_EnergyPoints = 10;
    this->_AttackDamage = 0;
    this->_MaxHitPoints = 10;
    this->_MaxEnergyPoints = 10;
    this->_MaxAttackDamage = 0;
    std::cout << name << " ClapTrap was created. Ready for Battle!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
    std::cout << this->_Name << " ClapTrap copy was created. Ready for Battle!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
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
    std::cout << this->_Name << " ClapTrap overload operator was called!" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << this->_Name << " ClapTrap was destroyed. He fought valiantly" << std::endl;
}

void ClapTrap::attack(const std::string &target)
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
    std::cout << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
    this->_EnergyPoints--;
    std::cout << this->_Name << " has " << this->getEP() << " energy left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->_Name << " took " << amount << " damage!" << std::endl;
    if (amount >= this->_HitPoints)
    {
        this->_HitPoints = 0;
        std::cout << this->_Name << " was killed, have mercy!" << std::endl;
    }
    else
    {
        this->_HitPoints -= amount;
        std::cout << this->_Name << " continues the fight! He's down to " << this->getHP() << " health!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount < 1)
    {
        std::cout << this->_Name << " can't repair by less than 1 health, dont be dumb!" << std::endl;
        return;
    }
    if (this->_EnergyPoints < 1)
    {
        std::cout << this->_Name << " does not have enough energy points to be repaired!" << std::endl;
        return;
    }
    if (this->_HitPoints < 1)
    {
        std::cout << this->_Name << " is dead. We dont have to tech to bring him back!" << std::endl;
        return;
    }
    if (this->_HitPoints == this->getMaxHP())
    {
        std::cout << this->_Name << " is already full health you silly goose!" << std::endl;
        return;
    }
    if (amount > (this->getMaxHP() - this->getHP()))
        amount = (this->getMaxHP() - this->getHP());
    std::cout << this->_Name << " has repaired " << amount << " hit points!" << std::endl;
    this->_HitPoints += amount;
    if (this->_HitPoints > this->_MaxHitPoints)
        this->_HitPoints = this->_MaxHitPoints;
    this->_EnergyPoints--;
    std::cout << this->_Name << " has " << this->getEP() << " energy left!" << std::endl;
    std::cout << this->_Name << " has " << this->getHP() << " health!" << std::endl;
}

unsigned int ClapTrap::getHP()
{
    return (this->_HitPoints);
}

unsigned int ClapTrap::getEP()
{
    return (this->_EnergyPoints);
}

unsigned int ClapTrap::getAD()
{
    return (this->_AttackDamage);
}

unsigned int ClapTrap::getMaxHP()
{
    return (this->_MaxHitPoints);
}

unsigned int ClapTrap::getMaxEP()
{
    return (this->_MaxEnergyPoints);
}

unsigned int ClapTrap::getMaxAD()
{
    return (this->_MaxAttackDamage);
}
