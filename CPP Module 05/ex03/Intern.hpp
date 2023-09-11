#pragma once

#include <iostream>
#include <map> 
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    private:

    public:
        // Constructor
        Intern();
        Intern(Intern const &copy);
        // Deconstructor
        ~Intern();
        // Operator overloads
        Intern  &operator=(const Intern &copy);
        // Member Functions
        AForm   *makeForm(std::string const &form, std::string const &target);
};