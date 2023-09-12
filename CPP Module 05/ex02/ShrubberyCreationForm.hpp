/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:00:20 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:00:27 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string const   _target;
        // Default Contructor in private so it cannot be intialized
        // with its default constructor.
        ShrubberyCreationForm();
    public:
        // Constructors
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        // Deconstructors
        ~ShrubberyCreationForm();
        // Operator Overloads
        ShrubberyCreationForm  &operator=(ShrubberyCreationForm const &copy);
        // Getter
        std::string const   &getTarget() const;
        // Member Functions
        void execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &os, AForm const &a);