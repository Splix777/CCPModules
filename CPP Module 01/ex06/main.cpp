/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:51:14 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:51:21 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int    complainLevel(std::string logLevel)
{
    if (logLevel == "DEBUG")
        return (0);
    else if (logLevel == "INFO")
        return (1);
    else if (logLevel == "WARNING")
        return (2);
    else if (logLevel == "ERROR")
        return (3);
    else
        return (-1);
}

void    harlSwitch(int level, Harl &harl)
{
    if (level >= 0)
    {
        switch (level)
        {
            case 3: // ERROR
                harl.complain("ERROR");
                break;
            case 2: // WARNING
                harl.complain("WARNING");
                break;
            case 1: // INFO
                harl.complain("INFO");
                break;
            case 0: // DEBUG
                harl.complain("DEBUG");
                break;
            default:
                break; // No need for an extra case
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <log_level>" << std::endl;
        return (1);
    }
    std::string logLevel = argv[1];
    Harl harl;
    int level = complainLevel(logLevel);
    if (level == -1)
    {
        std::cout << "Invalid complaint level!" << std::endl;
        return (1);
    }
    while (level < 4)
    {
        harlSwitch(level, harl);
        level++;
    }
    return (0);
}