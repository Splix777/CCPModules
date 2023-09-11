#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;

    zombie = newZombie("Zombie1");
    zombie->announce();
    delete zombie;
    randomChump("Random Zombie");
    return (0);
}