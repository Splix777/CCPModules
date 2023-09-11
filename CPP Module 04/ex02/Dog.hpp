#pragma once
#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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
    void        getIdeas(void) const;
    void        setIdeas(const std::string idea, int index);
private:
    // Attributes
    Brain       *_brain;
};

#endif