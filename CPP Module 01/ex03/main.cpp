#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    // Personal Tests:
    {
        // Create weapons
        Weapon sword("sword");
        Weapon axe("axe");

        // Create HumanA with initial weapon
        HumanA alice("Alice", sword);
        alice.attack();
        sword.setType("enchanted sword");
        alice.attack();

        // Create HumanB without initial weapon
        HumanB peter("Peter");
        peter.attack();

        // Set weapon for HumanB
        peter.setWeapon(axe);
        peter.attack();
        axe.setType("battle axe");
        peter.attack();

        // Create additional HumanA
        HumanA eve("Eve", sword);
        eve.attack();

        // Test changing weapon for HumanA
        eve.attack();
        axe.setType("mighty axe");
        eve.attack();
    }
    return (0);
}