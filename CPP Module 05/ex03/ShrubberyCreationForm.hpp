#pragma once

#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string const   _target;
        // Default Contructor in private so it cannot be intialized
        // with its default constructor.
        ShrubberyCreationForm();
    public:
        // Constructors
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        // Deconstructors
        ~ShrubberyCreationForm();
        // Operator Overloads
        ShrubberyCreationForm  &operator=(ShrubberyCreationForm const &copy);
        // Getter
        std::string const   &getTarget() const;
        // Member Functions
        void execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &os, AForm const &a);