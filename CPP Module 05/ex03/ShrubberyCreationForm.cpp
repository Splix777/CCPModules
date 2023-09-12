/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:02:17 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:02:17 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
    std::cout << this->getName() << " for your " << target << " has been created " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm("Shrubbery Creation Form", 145, 137), _target(copy.getTarget())
{
	*this = copy;
	std::cout << "Shrubbery Creation Form Copy Constructor called to copy " << copy.getName() << " into " << this->getName() << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form Deconstructor " << this->getName() << " called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "Shrubbery Creation Form Assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	//nothing to assign in this class, all constants
	return *this;
}

std::string const   &ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	if ((int)bureaucrat.getGrade() > this->getGradeToExecute())
    {
		std::cout << bureaucrat.getName() << " couldn't execute " << this->getName() << " because ";
        throw(Bureaucrat::GradeTooLowException());
    }
    else if (this->getSignedStatus() == true)
	{
		std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;
		std::ofstream outfile ((this->getTarget() + "_shrubbery").c_str(), std::ofstream::trunc);
		if (!outfile.is_open())
		{
			std::cerr << "Error opening file: " << this->getTarget() << "_shrubbery" << std::endl;
			return;
		}
		for (int i = 0; i < 2; i++)
		{
			outfile <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
		}
		outfile.close();	
	}
	else
		std::cout << this->getName() << " Form is not signed" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, ShrubberyCreationForm const &a)
{
    os << "Form " << a.getName() << ". Is signed: " << a.getSignedStatus() << ". Grade Needed to Sign: " << a.getGradeToSign() << ". Grade Needed to Execute: " << a.getGradeToExecute() << std::endl;
    return (os);
}