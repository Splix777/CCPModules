#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string const   _target;
        // Default Contructor in private so it cannot be intialized
        // with its default constructor.
        RobotomyRequestForm();
    public:
        // Constructors
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        // Deconstructors
        ~RobotomyRequestForm();
        // Operator Overloads
        RobotomyRequestForm  &operator=(RobotomyRequestForm const &copy);
        // Getter
        std::string const   &getTarget() const;
        // Member Functions
        void execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &os, AForm const &a);