/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:59:57 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/18 17:28:50 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // Try making creating abstract class
    // AForm form;
    // Create bureaucrats
    Bureaucrat highGradeBureaucrat("HighGrade", 1);
    Bureaucrat lowGradeBureaucrat("LowGrade", 50);
    Bureaucrat highGradeBureaucratCopy(highGradeBureaucrat);

    std::cout << highGradeBureaucrat << std::endl;
    std::cout << lowGradeBureaucrat << std::endl;
    std::cout << highGradeBureaucratCopy << std::endl;

    // Create forms
    ShrubberyCreationForm shrubberyForm("Garden");
    RobotomyRequestForm robotomyForm("John Doe");
    PresidentialPardonForm pardonForm("Some Criminal");

    std::cout << shrubberyForm << std::endl;
    std::cout << robotomyForm << std::endl;
    std::cout << pardonForm << std::endl;

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
