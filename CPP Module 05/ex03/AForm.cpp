/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:00:42 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:00:43 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << this->_name << " AForm was created." << std::endl;
}

AForm::AForm(AForm const &copy) : _name(copy._name + "_copy"), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "AForm Copy Constructor called." << std::endl;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << this->_name << " AForm was created." << std::endl;
}

AForm::~AForm()
{
    std::cout << this->_name << " AForm was destroyed." << std::endl;
}

AForm    &AForm::operator=(AForm const &copy)
{
    if (this != &copy)
        return (*this);
    return (*this);
}

std::string const   &AForm::getName() const
{
    return (this->_name);
}

int const   &AForm::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int const   &AForm::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

bool    AForm::getSignedStatus() const
{
    return (this->_signed);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if ((int)bureaucrat.getGrade() > this->getGradeToSign())
    {
		std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because ";
        throw(Bureaucrat::GradeTooLowException());
    }
    else if (this->getSignedStatus() == false)
	{
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
	}
	else
		std::cout << this->getName() << " AForm is already signed" << std::endl;
}

const char  *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char  *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

void    AForm::execute(Bureaucrat const &executor) const
{
    (void) executor;
}

std::ostream	&operator<<(std::ostream &os, AForm const &a)
{
    os << "AForm " << a.getName() << ". Is signed: " << a.getSignedStatus() << ". Grade Needed to Sign: " << a.getGradeToSign() << ". Grade Needed to Execute: " << a.getGradeToExecute() << std::endl;
    return (os);
}