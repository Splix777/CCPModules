/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:01:41 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/18 17:39:48 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{

    // Intern someRandomIntern;
    // AForm* rrf;
    // rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");



    
    // Create bureaucrats
    Bureaucrat highGradeBureaucrat("HighGrade", 1);
    Bureaucrat lowGradeBureaucrat("LowGrade", 50);
    std::cout << std::endl;
    // Create forms directly
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
    // Attempt to sign/execute forms with bureaucrats
    try {
        highGradeBureaucrat.signForm(shrubberyForm);
        highGradeBureaucrat.signForm(robotomyForm);
        highGradeBureaucrat.signForm(pardonForm);

        // Try to sign a form that doesn't exist
        if (wrongForm)
            highGradeBureaucrat.signForm(*wrongForm);

        highGradeBureaucrat.executeForm(shrubberyForm);
        highGradeBureaucrat.executeForm(robotomyForm);
        highGradeBureaucrat.executeForm(pardonForm);

        // Try to execute forms created by the intern to show they're different than the ones created directly
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

    return (0);
}
