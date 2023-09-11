#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // Create bureaucrats
    Bureaucrat highGradeBureaucrat("HighGrade", 1);
    Bureaucrat lowGradeBureaucrat("LowGrade", 50);

    // Create forms
    ShrubberyCreationForm shrubberyForm("Garden");
    RobotomyRequestForm robotomyForm("John Doe");
    PresidentialPardonForm pardonForm("Some Criminal");

    // Attempt to execute forms with bureaucrats
    try {
        highGradeBureaucrat.signForm(shrubberyForm);
        highGradeBureaucrat.signForm(shrubberyForm);
        highGradeBureaucrat.signForm(robotomyForm);
        highGradeBureaucrat.signForm(robotomyForm);
        highGradeBureaucrat.signForm(pardonForm);
        highGradeBureaucrat.signForm(pardonForm);

        highGradeBureaucrat.executeForm(shrubberyForm);
        highGradeBureaucrat.executeForm(robotomyForm);
        highGradeBureaucrat.executeForm(pardonForm);
        highGradeBureaucrat.executeForm(shrubberyForm);
        highGradeBureaucrat.executeForm(robotomyForm);
        highGradeBureaucrat.executeForm(pardonForm);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Attempt to execute forms with low-grade bureaucrat
    try {
        lowGradeBureaucrat.signForm(shrubberyForm);
        lowGradeBureaucrat.signForm(shrubberyForm);
        lowGradeBureaucrat.signForm(robotomyForm);
        lowGradeBureaucrat.signForm(robotomyForm);
        lowGradeBureaucrat.signForm(pardonForm);
        lowGradeBureaucrat.signForm(pardonForm);

        lowGradeBureaucrat.executeForm(shrubberyForm);
        lowGradeBureaucrat.executeForm(robotomyForm);
        lowGradeBureaucrat.executeForm(pardonForm);
        lowGradeBureaucrat.executeForm(shrubberyForm);
        lowGradeBureaucrat.executeForm(robotomyForm);
        lowGradeBureaucrat.executeForm(pardonForm);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
