#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << this->_name << " Form was created." << std::endl;
}

Form::Form(Form const &copy) : _name(copy._name + "_copy"), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "Form Copy Constructor called." << std::endl;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << this->_name << " Form was created." << std::endl;
}

Form::~Form()
{
    std::cout << this->_name << " Form was destroyed." << std::endl;
}

Form    &Form::operator=(Form const &copy)
{
    if (this != &copy)
    {
        this->_signed = copy._signed;
    }
    std::cout << "Form Assignation operator called" << std::endl;
    return (*this);
}

std::string const   &Form::getName() const
{
    return (this->_name);
}

int const   &Form::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int const   &Form::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

bool    Form::getSignedStatus() const
{
    return (this->_signed);
}

void Form::beSigned(Bureaucrat &bureaucrat)
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
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

const char  *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char  *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

std::ostream	&operator<<(std::ostream &os, Form const &a)
{
    os << "Form " << a.getName() << ". Is signed: " << a.getSignedStatus() << ". Grade Needed to Sign: " << a.getGradeToSign() << ". Grade Needed to Execute: " << a.getGradeToExecute() << std::endl;
    return (os);
}