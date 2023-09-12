/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:57:39 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:57:39 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef Brain_HPP
# define Brain_HPP

# include "Animal.hpp"

class Brain
{
    private:
        std::string *ideas;

    public:
        Brain();
        Brain(const Brain &copy);
        ~Brain();
        Brain &operator=(const Brain &copy);
        std::string getIdea(int i);
        void        setIdea(int i, std::string idea);
};

#endif