/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:00:11 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:00:12 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
    std::cout << this->getName() << " for your " << target << " has been created " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm("Robotomy Request Form", 72, 45), _target(copy.getTarget())
{
	*this = copy;
	std::cout << "Robotomy Request Form Copy Constructor called to copy " << copy.getName() << " into " << this->getName() << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form Deconstructor " << this->getName() << " called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "Robotomy Request Form Assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	//nothing to assign in this class, all constants
	return *this;
}

std::string const   &RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	if ((int)bureaucrat.getGrade() > this->getGradeToExecute())
    {
		std::cout << bureaucrat.getName() << " couldn't execute " << this->getName() << " because ";
        throw(Bureaucrat::GradeTooLowException());
    }
    else if (this->getSignedStatus() == true)
	{
		std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;
		std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
	}
	else
		std::cout << this->getName() << " Form is not signed" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, RobotomyRequestForm const &a)
{
    os << "Form " << a.getName() << ". Is signed: " << a.getSignedStatus() << ". Grade Needed to Sign: " << a.getGradeToSign() << ". Grade Needed to Execute: " << a.getGradeToExecute() << std::endl;
    return (os);
}