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