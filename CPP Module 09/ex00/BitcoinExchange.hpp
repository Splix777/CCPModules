/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:05:33 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/27 12:01:06 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>     // Needed for input/output operations
#include <string>       // Needed for string manipulation
#include <cstdlib>      // Needed for std::atoi
#include <ctime>        // Needed for time-related functions
#include <fstream>      // Needed for file operations
#include <stdexcept>    // Needed for std::runtime_error
#include <map>          // Needed for std::map

class BitcoinExchange
{
private:
    // Container to store data (int = date, double = exchange rate)
    std::map<int, double> data;
    // Variables to store first available date
    double  firstValue;
    // Helper Functions
    int         validIntKey(const std::string &key, const std::string &delim) const;
    double		validValue(const std::string &value, const std::string &delim) const;
public:
    // Constructors
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    // Destructor
    ~BitcoinExchange();
    // Operator Overloads
    BitcoinExchange &operator=(const BitcoinExchange &copy);
    // Member Functions
    void loadData();
    void printExchangeRates(const std::string &file) const;
    // Member Helper Functions
    bool checkDateFormat(const std::string &date) const;
    void trimFrontBack(std::string &s) const;
    struct tm *getTime() const;
};

bool isNumber(const std::string &s);

#endif