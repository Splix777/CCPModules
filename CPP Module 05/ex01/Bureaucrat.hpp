/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:59:15 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:59:15 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const   _name;
        int                 _grade;

    public:
        // Constructors
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        // Deconstructor
        ~Bureaucrat();
        // Getters
        std::string const   &getName() const;
        int const   &getGrade() const;
        // Member Functions
        void    incrementGrade();
        void    decrementGrade();
        void    signForm(Form &form);
        // Overload Operators
        Bureaucrat  &operator=(Bureaucrat const &copy);
        // Exceptions
        class    GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class    GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();            
        };

};

std::ostream    &operator<<(std::ostream &os, Bureaucrat const &b);