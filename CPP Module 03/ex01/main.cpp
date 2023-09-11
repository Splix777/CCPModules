#include "ScavTrap.hpp"

int main()
{
    // Create ScavTrap instances
    ScavTrap scav1("Guardian1");
    std::cout << std::endl;
    ScavTrap scav2("Guardian2");
    std::cout << std::endl;
    std::cout << std::endl;

    // Test guardGate()
    scav1.attack("Guardian2");
    std::cout << std::endl;
    scav1.guardGate(); // Should be in Gate Keeper mode
    std::cout << std::endl;
    scav1.takeDamage(150); // Inflict damage greater than hit points
    std::cout << std::endl;
    scav1.guardGate(); // Should be dead, can't guard the gate
    std::cout << std::endl;
    std::cout << std::endl;

    // Test copy constructor
    ScavTrap scavCopy(scav2); // Create a copy of scav2
    std::cout << std::endl;
    scavCopy.guardGate(); // Should be in Gate Keeper mode
    std::cout << std::endl;
    std::cout << std::endl;

    // Test assignment operator
    ScavTrap scav3("Guardian3");
    std::cout << std::endl;
    scav3 = scav1; // Assign scav1's values to scav3
    std::cout << std::endl;
    scav3.guardGate(); // Should be dead, can't guard the gate
    std::cout << std::endl;
    std::cout << std::endl;

    // Test default constructor and guardGate
    ScavTrap scavDefault;
    std::cout << std::endl;
    scavDefault.guardGate(); // Should be in Gate Keeper mode
    std::cout << std::endl;
    std::cout << std::endl;

    // Test initializing with a name using explicit constructor
    ScavTrap scavExplicit;
    std::cout << std::endl;
    scavExplicit = ScavTrap("ExplicitGuardian");
    std::cout << std::endl;
    scavExplicit.guardGate(); // Should be in Gate Keeper mode
    std::cout << std::endl; 

    return (0);
}
