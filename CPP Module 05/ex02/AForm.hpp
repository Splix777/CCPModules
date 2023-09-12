/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:59:41 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:59:42 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string	_name;
        bool                _signed;
        int const           _gradeToSign;
        int const           _gradeToExecute;

    public:
        // Constructor
        AForm();
        AForm(AForm const &copy);
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
        // Deconstructor
        virtual ~AForm();
        // Operator Overloads
        AForm	&operator=(AForm const &copy);
        // Member Functions
        std::string const   &getName() const;
		int const			&getGradeToSign() const;
		int const			&getGradeToExecute() const;
        bool				getSignedStatus() const;
		void				beSigned(Bureaucrat &bureaucrat);
        virtual void        execute(Bureaucrat const &executor) const = 0;
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

std::ostream	&operator<<(std::ostream &os, AForm const &a);