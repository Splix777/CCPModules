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
