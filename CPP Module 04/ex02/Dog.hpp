/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:41 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:41 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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