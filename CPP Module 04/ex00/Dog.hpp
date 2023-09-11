#pragma once
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
public:
    // Constructors and destructor
    Dog();
    Dog(const Dog &copy);
    ~Dog();
    // Operator overloads
    Dog         &operator=(const Dog &copy);
    // Member functions
    void        makeSound(void) const;
};

#endif