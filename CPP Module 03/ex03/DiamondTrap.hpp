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