#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
    // Constructors & Destructors
    ClapTrap(void);
    ~ClapTrap(void);
    ClapTrap(const std::string &name);
    // Copy Constructor
    ClapTrap(const ClapTrap &copy);
    // Operator Overload
    ClapTrap &operator=(const ClapTrap &copy);
    // ClapTrap Actions
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    // Current Stat Getters
    unsigned int getHP();
    unsigned int getEP();
    unsigned int getAD();
    // Max Stat Getters
    unsigned int getMaxHP();
    unsigned int getMaxEP();
    unsigned int getMaxAD();

protected:
    // Name
    std::string _Name;
    // Stats
    unsigned int _HitPoints;
    unsigned int _EnergyPoints;
    unsigned int _AttackDamage;
    // Max Stats
    unsigned int _MaxHitPoints;
    unsigned int _MaxEnergyPoints;
    unsigned int _MaxAttackDamage;
};

#endif // CLAPTRAP_HPP
