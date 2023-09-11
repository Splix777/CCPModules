#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>

class Zombie
{
private:
    std::string _name;

public:
    Zombie(std::string name);
    Zombie(void);
    ~Zombie(void);
    void announce(void);
    void giveName(std::string name);
};

Zombie  *newZombie(std::string name);
Zombie  *zombieHorde(int N, std::string name);