#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
    std::cout << this->getName() << " for your " << target << " has been created " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): AForm("Presidential Pardon Form", 25, 5), _target(copy.getTarget())
{
	*this = copy;
	std::cout << "Presidential Pardon Form Copy Constructor called to copy " << copy.getName() << " into " << this->getName() << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form Deconstructor " << this->getName() << " called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << "Presidential Pardon Form Assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	//nothing to assign in this class, all constants
	return *this;
}

std::string const   &PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	if ((int)bureaucrat.getGrade() > this->getGradeToExecute())
    {
		std::cout << bureaucrat.getName() << " couldn't execute " << this->getName() << " because ";
        throw(Bureaucrat::GradeTooLowException());
    }
    else if (this->getSignedStatus() == true)
	{
		std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else
		std::cout << this->getName() << " Form is not signed" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, PresidentialPardonForm const &a)
{
    os << "Form " << a.getName() << ". Is signed: " << a.getSignedStatus() << ". Grade Needed to Sign: " << a.getGradeToSign() << ". Grade Needed to Execute: " << a.getGradeToExecute() << std::endl;
    return (os);
}