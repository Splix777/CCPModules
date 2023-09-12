/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:22 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:23 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
protected:
    std::string _type;

public:
    // Constructors/Destructors
    AAnimal();
    AAnimal(AAnimal const &copy);
    virtual ~AAnimal();

    // Operators Overload
    AAnimal &operator=(AAnimal const &copy);

    // Abstract Method (pure virtual)
    virtual void makeSound() const = 0;  // Note the '= 0' here
    // This indicates that the method is a pure virtual method.
    // A pure virtual method is a method that is declared in the base class
    // but not defined.  It is the responsibility of the derived class to
    // define the method.  If the derived class does not define the method,
    // then the derived class will also be an abstract class.
    // An abstract class is a class that cannot be instantiated.  It can only
    // be used as a base class for other classes.
    std::string getType(void) const;
};


#endif