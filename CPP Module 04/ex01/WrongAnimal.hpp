#pragma once
#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <iostream>

class WrongAnimal
{
protected:
    std::string _type;

public:
    // Constructors/Destructors
    WrongAnimal();
    WrongAnimal(WrongAnimal const &copy);
    virtual ~WrongAnimal();
    // Operators Overload
    WrongAnimal  &operator=(WrongAnimal const &copy);
    // Actions
    virtual void    makeSound() const;
    std::string     getType(void) const;
};

#endif