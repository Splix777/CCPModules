#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "An intern was created to be used and abused." << std::endl;
}

Intern::Intern(Intern const &copy)
{
    *this = copy;
    std::cout << "Intern Copy Constructor called." << std::endl;
}

Intern::~Intern()
{
    std::cout << "An Intern was put out of its misery." << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
    if (this != &copy)
    {
        *this = copy;
        std::cout << "Intern overload operator called." << std::endl;
    }
    return (*this);
}

static AForm    *createShrubberyCreationForm(std::string const &target)
{
    std::cout << "Intern creates " << target << " form." << std::endl;
    return (new ShrubberyCreationForm(target));
}

static AForm    *createRobotomyRequestForm(std::string const &target)
{
    std::cout << "Intern creates " << target << " form." << std::endl;
    return (new RobotomyRequestForm(target));
}

static AForm    *createPresidentialPardonForm(std::string const &target)
{
    std::cout << "Intern creates " << target << " form." << std::endl;
    return (new PresidentialPardonForm(target));
}

AForm   *Intern::makeForm(std::string const &form, std::string const &target)
{
    AForm *(*forms[])(std::string const &target) = { &createShrubberyCreationForm,
                                                     &createRobotomyRequestForm,
                                                     &createPresidentialPardonForm };
    std::string formNames[] = { "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm" };
    int i = 0;

    while (i < 3)
    {
        if (formNames[i] == form)
            return (forms[i](target));
        i++;
    }
    // If form name is not recognized, print an error message and return NULL
    std::cerr << "Unknown form: " << form << std::endl;
    return (NULL);
}
