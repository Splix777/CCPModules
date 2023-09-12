/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:00:07 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:00:07 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
        std::string const   _target;
        // Default Contructor in private so it cannot be intialized
        // with its default constructor.
        PresidentialPardonForm();
    public:
        // Constructors
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        // Deconstructors
        ~PresidentialPardonForm();
        // Operator Overloads
        PresidentialPardonForm  &operator=(PresidentialPardonForm const &copy);
        // Getter
        std::string const   &getTarget() const;
        // Member Functions
        void execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &os, AForm const &a);