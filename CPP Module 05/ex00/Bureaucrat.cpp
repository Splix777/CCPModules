#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    std::cout << this->_name << ", Bureaucrat is created! His grade is: " << this->_grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << this->_name << ", Bureaucrat is destroyed!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade)
{
    std::cout << this->_name << "Bureaucrat Copy Constructor called." << std::endl;
}

Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &copy)
{
    if (this != &copy)
    {
        this->_grade = copy._grade;
    }
    std::cout << this->_name << "Bureaucrat Assignation operator called" << std::endl;
    return (*this);
}
// Using Member Initialization since name is a const string. Const variables must be initialized
// using member initialization list. Order matters, specially if using base classes etc.
Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
    if (this->_grade > 150)
        throw GradeTooLowException();
    else if (this->_grade < 1)
        throw GradeTooHighException();
    else
        std::cout << this->_name << ", Bureaucrat is created! His grade is: " << this->_grade << std::endl;
}

std::string const   &Bureaucrat::getName() const
{
    return (this->_name);
}

int const   &Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade()
{
    _grade--;
    if (_grade < 1)
    {
        _grade = 1;
        std::cout << "Cannot increaese Bureaucrat grade, already at its highest!" << std::endl;
        throw GradeTooHighException();
    }
    std::cout << "Bureaucrat grade was increased to: " << this->getGrade() << std::endl;
}

void    Bureaucrat::decrementGrade()
{
    _grade++;
    if (_grade > 150)
    {
        _grade = 150;
        std::cout << "Cannot decrease Bureaucrat grade, already at its highest!" << std::endl;
        throw GradeTooLowException();
    }
    std::cout << "Bureaucrat grade was decreased to: " << this->getGrade() << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << "Bureaucrat " << b.getName() << ": His grade is: " << b.getGrade() << std::endl;
	return (os);
}