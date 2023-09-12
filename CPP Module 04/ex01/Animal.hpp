/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:57:31 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:57:31 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
    std::string _type;

public:
    // Constructors/Destructors
    Animal();
    Animal(Animal const &copy);
    virtual ~Animal();
    // Operators Overload
    Animal  &operator=(Animal const &copy);
    // Actions
    virtual void    makeSound() const;
    std::string     getType(void) const;
};

#endif
/*
1. private:
    -   Members declared as private are not accessible from outside
        the class in which they are defined.

    -   They are only accessible within the class itself. Other
        classes, even derived classes, cannot access private members directly.

    -   Private members are often used to encapsulate the internal
        implementation details of a class, making them hidden from
        external users of the class.

    -   Private members can only be accessed by member functions and
        friends of the class.

2. protected:
    -   Members declared as protected have the same access restrictions as
        private members within the class in which they are defined.

    -   However, they have additional visibility to derived classes
        (classes that inherit from the base class). Derived classes can
        access protected members as if they were private members of the
        derived class itself.

    -   Protected members are often used when you want to provide access
        to derived classes for purposes like inheritance and overriding.

    -   Protected members can only be accessed by member functions and
        friends of the class.
*/