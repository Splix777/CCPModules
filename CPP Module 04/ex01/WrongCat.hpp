#pragma once
#ifndef WrongCat_HPP
# define WrongCat_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    // Constructors and destructor
    WrongCat();
    WrongCat(const WrongCat &copy);
    ~WrongCat();
    // Operator overloads
    WrongCat         &operator=(const WrongCat &copy);
    // Member functions
    void        makeSound(void) const;
};

#endif