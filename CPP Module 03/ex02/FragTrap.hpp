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
