/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:09 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:10 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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