/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:05:36 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:05:37 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc <input.txt>" << std::endl;
        return (1);
    }
    std::string file = argv[1];
    BitcoinExchange exchange;
    try
    {
        exchange.loadData();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " <.csv file!>" << std::endl;
    }
    try
    {
        exchange.printExchangeRates(file);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " <.txt file!>" << std::endl;
    }
    
    return (0);
}