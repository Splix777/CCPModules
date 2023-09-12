/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:57:00 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:57:01 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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