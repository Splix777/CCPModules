#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    // Create bureaucrats
    Bureaucrat highGradeBureaucrat("HighGrade", 1);
    Bureaucrat lowGradeBureaucrat("LowGrade", 50);
    std::cout << std::endl;
    // Create forms
    ShrubberyCreationForm shrubberyForm("Garden");
    RobotomyRequestForm robotomyForm("John Doe");
    PresidentialPardonForm pardonForm("Some Criminal");
    std::cout << std::endl;

    // Create an instance of the Intern
    Intern someRandomIntern;
    std::cout << std::endl;

    // Use the intern to create forms
    AForm *shrubberyFormByIntern = someRandomIntern.makeForm("ShrubberyCreationForm", "Garden");
    AForm *robotomyFormByIntern = someRandomIntern.makeForm("RobotomyRequestForm", "John Doe");
    AForm *pardonFormByIntern = someRandomIntern.makeForm("PresidentialPardonForm", "Some Criminal");
    AForm *wrongForm = someRandomIntern.makeForm("NonExistantForm", "Intern");
    std::cout << std::endl;
    // Attempt to execute forms with bureaucrats
    try {
        highGradeBureaucrat.signForm(shrubberyForm);
        highGradeBureaucrat.signForm(robotomyForm);
        highGradeBureaucrat.signForm(pardonForm);

        // Fix the signForm call for wrongForm
        if (wrongForm)
            highGradeBureaucrat.signForm(*wrongForm);

        highGradeBureaucrat.executeForm(shrubberyForm);
        highGradeBureaucrat.executeForm(robotomyForm);
        highGradeBureaucrat.executeForm(pardonForm);

        // Execute forms created by Intern
        if (shrubberyFormByIntern)
            highGradeBureaucrat.executeForm(*shrubberyFormByIntern);
        if (robotomyFormByIntern)
            highGradeBureaucrat.executeForm(*robotomyFormByIntern);
        if (pardonFormByIntern)
            highGradeBureaucrat.executeForm(*pardonFormByIntern);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    // Clean up memory
    delete shrubberyFormByIntern;
    delete robotomyFormByIntern;
    delete pardonFormByIntern;

    return 0;
}
