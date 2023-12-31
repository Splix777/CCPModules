/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:42:31 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:42:32 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 1)
    {
        std::cout << "Invalid number of arguments!" << std::endl;
        return (1);
    }
    PhoneBook phoneBook;
    std::string input;
    while (input != "EXIT")
    {
        displayWelcome();
        std::cin >> input;
        if (input == "ADD")
            phoneBook.addContact();
        else if (input == "SEARCH")
            phoneBook.searchContact();
        else if (input != "EXIT")
        {
            std::cout << "Invalid command!" << std::endl;
            usleep(1000000);
        }
        clearScreen();
    }
    return (0);
}
