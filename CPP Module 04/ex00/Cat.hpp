/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:56:55 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:56:55 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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