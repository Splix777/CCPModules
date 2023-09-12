/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:59:20 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:59:21 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string	_name;
        bool                _signed;
        int const           _gradeToSign;
        int const           _gradeToExecute;

    public:
        // Constructor
        Form();
        Form(Form const &copy);
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
        // Deconstructor
        ~Form();
        // Operator Overloads
        Form	&operator=(Form const &copy);
        // Member Functions
        std::string const   &getName() const;
		int const			&getGradeToSign() const;
		int const			&getGradeToExecute() const;
        bool				getSignedStatus() const;
		void				beSigned(Bureaucrat &bureaucrat);
		// Exceptions
		class GradeTooHighException : public std::exception
		{
            public:
                virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
            public:
                virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, Form const &a);