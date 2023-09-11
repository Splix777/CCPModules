#pragma once
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
public:
    // Constructors and destructor
    Cat();
    Cat(const Cat &copy);
    ~Cat();
    // Operator overloads
    Cat         &operator=(const Cat &copy);
    // Member functions
    void        makeSound(void) const;
};

#endif