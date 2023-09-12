/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:35 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:36 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
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
    void        getIdeas(void) const;
    void        setIdeas(const std::string idea, int index);
private:
    // Attributes
    Brain       *_brain;
};

#endif