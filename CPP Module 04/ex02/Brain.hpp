/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:30 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:31 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    protected:
        std::string ideas[100];
    public:
        // Constructors and destructor
        Brain();
        Brain(const Brain &copy);
        virtual ~Brain();
        // Operator overloads
        Brain   &operator=(const Brain &copy);
        // Member functions
        const std::string   getIdeas(size_t i);
        const std::string   *getIdeasPointer(size_t i);
        void    setIdeas(size_t i, std::string idea);
};

#endif