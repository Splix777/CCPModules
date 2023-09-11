#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
    {
        std::cout << "\033[34mConstructing\033[0m" << std::endl;
        ClapTrap a;
        ClapTrap b("Cody");

        std::cout << "\033[34mTesting\033[0m" << std::endl;
        a.attack("some other robot");
        a.takeDamage(10);
        a.takeDamage(10);
        a.beRepaired(5);
        a.attack("some other other robot");
        b.beRepaired(3);
        for (int i = 0; i < 12; i++)
            b.attack("Cody-clone");
        b.beRepaired(3);
        std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
    }
    
    std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
    {
        std::cout << "\033[34mConstructing\033[0m" << std::endl;
        ScavTrap a;
        ScavTrap b("Savage");

        std::cout << "\033[34mTesting\033[0m" << std::endl;
        a.attack("CloneTrap");
        a.beRepaired(22);
        a.takeDamage(21);
        a.beRepaired(22);
        a.guardGate();
        a.guardGate();
        b.attack("Savage-clone");
        b.takeDamage(101);
        b.takeDamage(15);
        b.attack("ScavTrap-clone");
        std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
    }
    
    std::cout << "\n\n### TESTING FRAGTRAP ###\n" << std::endl;
    {
        std::cout << "\033[34mConstruct"_scav_name"ing\033[0m" << std::endl;
        FragTrap a;
        FragTrap b("Chadd");

        std::cout << "\033[34mTesting\033[0m" << std::endl;
        a.highFivesGuys();
        a.attack("some random dude");
        a.takeDamage(101);
        a.takeDamage(1);
        a.attack("some random dude");
        b.highFivesGuys();
        std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
    }
    
    std::cout << "\n\n### TESTING DIAMONDTRAP ###\n" << std::endl;
    {
        std::cout << "\033[34mConstructing\033[0m" << std::endl;
        DiamondTrap a;
        DiamondTrap b("Giga Chadd");
        DiamondTrap c(a);

        std::cout << "\033[34mTesting\033[0m" << std::endl;
        a.whoAmI();
        a.attack("some super random dude");
        b.whoAmI();
        b.attack("Chadd-clone");
        c.whoAmI();
        std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
    }
    return (0);
}
/*
DiamondTrap class, which inherits virtually from both FragTrap and ScavTrap.

Here's a quick recap of the inheritance hierarchy:

       ClapTrap
        /     \
FragTrap     ScavTrap
        \     /
      DiamondTrap

Without virtual inheritance, if both FragTrap and ScavTrap inherited directly from ClapTrap,
and DiamondTrap inherited from both FragTrap and ScavTrap, you would have two instances of
the ClapTrap base class within DiamondTrap. This would lead to ambiguity and the diamond problem,
where the compiler wouldn't know which ClapTrap to use.

If you didn't use virtual inheritance and instead inherited directly from both FragTrap and
ScavTrap, you would have encountered compilation errors due to ambiguity and confusion in
function resolution.

1. When a DiamondTrap object is created, it goes through the following steps:

         +------------------------+
Step 1:  |  Construct ClapTrap   |
         +------------------------+
               |
               v
         +------------------------+
Step 2:  |  Construct FragTrap   |          
         +------------------------+
               |
               v
         +------------------------+
Step 3:  |  Construct ScavTrap   |
         +------------------------+
               |
               v
         +------------------------+
Step 4:  |  Construct DiamondTrap|
         +------------------------+

        ClapTrap
           ^
           |
  +--------+--------+
  |                 |
FragTrap          ScavTrap
   ^                 ^
   |                 |
DiamondTrap   (virtual inheritance)


2. When a DiamondTrap object is destroyed, it goes through the following steps:

         +------------------------+
Step 1:  |  Destruct DiamondTrap |
         +------------------------+
               |
               v
         +------------------------+
Step 2:  |  Destruct ScavTrap    |
         +------------------------+
               |
               v
         +------------------------+
Step 3:  |  Destruct FragTrap    |
         +------------------------+
               |
               v
         +------------------------+
Step 4:  |  Destruct ClapTrap    |
         +------------------------+
*/
