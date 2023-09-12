/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:42:55 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:42:57 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook() : index(0), full(false) {}

PhoneBook::~PhoneBook() {}

void    PhoneBook::addContact()
{
    clearScreen();
    displayAdd();
    if (index == 8 || full == true)
    {
        std::cout << "Phonebook is full." << std::endl;
        std::cout << "Do you want to overwrite the oldest contact? (y/n)" << std::endl;
        std::string input;
        std::cin >> input;
        if (input == "n")
            return ;
        else if (input != "y")
        {
            std::cout << "Invalid input!" << std::endl;
            addContact();
        }
        full = true;
        index = (index) % 8 ;
    }
    contact[index].setFirstName();
    contact[index].setLastName();
    contact[index].setNickname();
    contact[index].setPhoneNumber();
    contact[index].setDarkestSecret();
    index++;
    clearScreen();
    displayAdd();
    std::cout << "Do you want to add another contact? (y/n)" << std::endl;
    std::string input;
    std::cin >> input;
    if (input == "n")
        return ;
    else if (input == "y")
        addContact();
    else
    {
        std::cout << "Invalid input!" << std::endl;
        addContact();
    }
}

void    PhoneBook::searchContact()
{
    clearScreen();
    std::cout << "_____________________________________________" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|---------------Search Results--------------|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|   Index  |First Name|Last Name |Nickname  |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << "|" << std::setw(10) << i + 1 << "|";
        printShortenedContact(contact[i].getFirstName());
        printShortenedContact(contact[i].getLastName());
        printShortenedContact(contact[i].getNickname());
        std::cout << std::endl;
    }

    std::cout << "|___________________________________________|" << std::endl;
    std::cout << "|Which contact would you like to see? (1-8) |" << std::endl;
    std::cout << "|EXIT to return to homescreen!              |" << std::endl;
    std::cout << "|___________________________________________|" << std::endl;
    std::cout << "|>> ";
    std::string input;
    std::cin >> input;
    if (input == "EXIT")
        return;
    else if (input == "1")
        printContact(0);
    else if (input == "2")
        printContact(1);
    else if (input == "3")
        printContact(2);
    else if (input == "4")
        printContact(3);
    else if (input == "5")
        printContact(4);
    else if (input == "6")
        printContact(5);
    else if (input == "7")
        printContact(6);
    else if (input == "8")
        printContact(7);
    else
    {
        std::cout << "Invalid input!" << std::endl;
        usleep(1000000);
        searchContact();
    }
}

void    PhoneBook::printContact(int index) const
{
    clearScreen();
    std::cout << "_____________________________________________" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|---------------Display Contact-------------|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|   Index  |First Name|Last Name |Nickname  |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    
    std::cout << "|" << std::setw(10) << index + 1 << "|";
    printShortenedContact(contact[index].getFirstName());
    printShortenedContact(contact[index].getLastName());
    printShortenedContact(contact[index].getNickname());
    std::cout << std::endl;
    
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|First Name    : ";

    printFullContact(contact[index].getFirstName());

    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|Last Name     : ";

    printFullContact(contact[index].getLastName());

    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|Nickname      : ";

   printFullContact(contact[index].getNickname());

    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|Phone Number  : ";

    printFullContact(contact[index].getPhoneNumber());

    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|Darkest Secret: ";

    printFullContact(contact[index].getDarkestSecret());

    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|___________________________________________|" << std::endl;
    std::cout << "|Which contact would you like to see? (1-8) |" << std::endl;
    std::cout << "|Press any key to return to homescreen!     |" << std::endl;
    std::cout << "|___________________________________________|" << std::endl;
    std::cout << "|>> ";

    std::string input;
    std::cin >> input;

    if (input == "EXIT")
        return;
    else if (input == "1")
        printContact(0);
    else if (input == "2")
        printContact(1);
    else if (input == "3")
        printContact(2);
    else if (input == "4")
        printContact(3);
    else if (input == "5")
        printContact(4);
    else if (input == "6")
        printContact(5);
    else if (input == "7")
        printContact(6);
    else if (input == "8")
        printContact(7);
    else
        return ;
}

Contact PhoneBook::getContact(int index) const
{
    return (this->contact[index]);
}
