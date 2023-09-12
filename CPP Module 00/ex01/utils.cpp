/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:43:16 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:43:18 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #elif __APPLE__
        system("clear");
    #else
        system("clear");
    #endif
}

void    printShortenedContact(std::string str)
{
    if (str.length() > 10)
    {
        str.resize(9);
        str.append(".");
    }
    std::cout << std::setw(10) << str << "|";
}

void    printFullContact(std::string str)
{
    std::cout << str;;
    int lenght = str.length();
    for (int i = 0; i < (27 - lenght); i++)
        std::cout << " ";
    std::cout << "|" << std::endl;
}
