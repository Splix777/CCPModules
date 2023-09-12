/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:42:06 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:42:08 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"

Contact::Contact()
{
    this->_firstName = "";
    this->_lastName = "";
    this->_nickname = "";
    this->_phoneNumber = "";
    this->_darkestSecret = "";
}

Contact::~Contact() {}

void    Contact::setFirstName()
{
    std::string input;

    clearScreen();
    displayAdd();
    std::cout << "First Name(Max 20 characters): ";
    std::cin >> input;
    if (input.empty())
    {
        std::cout << "Invalid input!" << std::endl;
        setFirstName();
    }
    if (input.size() > 20)
    {
        std::cout << "First name is too long! Max 12 characts." << std::endl;
        setFirstName();
    }
    else
        this->_firstName = input;
}

void    Contact::setLastName()
{
    std::string input;

    clearScreen();
    displayAdd();
    std::cout << "Last Name(Max 20 characters): ";
    std::cin >> input;
    if (input.empty())
    {
        std::cout << "Invalid input!" << std::endl;
        setLastName();
    }
    if (input.size() > 20)
    {
        std::cout << "Last name is too long! Max 12 characts." << std::endl;
        setLastName();
    }
    else
        this->_lastName = input;
}

void    Contact::setNickname()
{
    std::string input;

    clearScreen();
    displayAdd();
    std::cout << "Nickname(Max 20 characters): ";
    std::cin >> input;
    if (input.empty())
    {
        std::cout << "Invalid input!" << std::endl;
        setNickname();
    }
    if (input.size() > 20)
    {
        std::cout << "Nickname is too long! Max 12 characts." << std::endl;
        setNickname();
    }
    else
        this->_nickname = input;
}

void    Contact::setPhoneNumber()
{
    std::string input;

    clearScreen();
    displayAdd();
    std::cout << "Phone Number <123-456-7890> :";
    std::cin >> input;
    if (input.empty())
    {
        std::cout << "Invalid input!" << std::endl;
        setPhoneNumber();
    }
    if (!correctPhoneFormat(input))
    {
        std::cout << "Invalid phone format!" << std::endl;
        setPhoneNumber();
    }
    else
        this->_phoneNumber = input;
}

void    Contact::setDarkestSecret()
{
    std::string input;

    clearScreen();
    displayAdd();
    std::cout << "Darkest Secret(Max 20 characters): ";
    std::cin >> input;
    if (input.empty())
    {
        std::cout << "Invalid input!" << std::endl;
        setDarkestSecret();
    }
    if (input.size() > 20)
    {
        std::cout << "Darkest secret is too long! Max 12 characts." << std::endl;
        setDarkestSecret();
    }
    else
        this->_darkestSecret = input;
}

std::string Contact::getFirstName() const { return (this->_firstName); }

std::string Contact::getLastName() const { return (this->_lastName); }

std::string Contact::getNickname() const { return (this->_nickname); }

std::string Contact::getPhoneNumber() const { return (this->_phoneNumber); }

std::string Contact::getDarkestSecret() const { return (this->_darkestSecret); }

int Contact::correctPhoneFormat(std::string input) const
{
    if (input.size() != 12 && input.size() != 10)
        return (0);
    for (size_t i = 0; i < input.size(); i++)
    {
        if (i == 3 || i == 7)
        {
            if (input[i] != '-')
                return (0);
        }
        else if (!isdigit(input[i]))
            return (0);
    }
    return (1);
}
