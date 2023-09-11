#include "Zombie.hpp"

int main(int argc, char **argv)
{
    int     N;

    if (argc == 2)
    {
        N = atoi(argv[1]);
        Zombie  *horde;
        horde = zombieHorde(N, "Bobs");
        for (int i = 0; i < N; i++)
            horde[i].announce();
        delete[] horde;
    }
    else
        std::cout << "Usage: ./zombieHorde [number of zombies]" << std::endl;
    return (0);    
}