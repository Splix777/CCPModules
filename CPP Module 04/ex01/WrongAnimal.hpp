/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:04 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:04 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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