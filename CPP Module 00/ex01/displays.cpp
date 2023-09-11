#include "utils.hpp"

void    displayWelcome()
{
    clearScreen();
    std::cout << "_______________________________________________" << std::endl;
    std::cout << "|---------------------------------------------|" << std::endl;
    std::cout << "|----------Welcome to the Phonebook!----------|" << std::endl;
    std::cout << "|---------------------------------------------|" << std::endl;
    std::cout << "|Please enter a command:                      |" << std::endl;
    std::cout << "|---------------------------------------------|" << std::endl;
    std::cout << "|                                             |" << std::endl;
    std::cout << "|ADD: Add a new contact                       |" << std::endl;
    std::cout << "|                                             |" << std::endl;
    std::cout << "|SEARCH: Search for a contact                 |" << std::endl;
    std::cout << "|                                             |" << std::endl;
    std::cout << "|EXIT: Exit the Phonebook                     |" << std::endl;
    std::cout << "|                                             |" << std::endl;
    std::cout << "|_____________________________________________|" << std::endl;
    std::cout << "|>> ";
}

void    displayAdd()
{
    clearScreen();
    std::cout << "_____________________________________________________" << std::endl;
    std::cout << "|---------------------------------------------------|" << std::endl;
    std::cout << "|-------------------Add a Contact!------------------|" << std::endl;
    std::cout << "|---------------------------------------------------|" << std::endl;
    std::cout << "|                                                   |" << std::endl;   
}

