/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:05:30 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/27 12:04:45 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
// Default Constructor
BitcoinExchange::BitcoinExchange() : firstValue(0) {}
// Destructor
BitcoinExchange::~BitcoinExchange() {}
// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    data = copy.data;
    firstValue = copy.firstValue;
}
// Assignment Operator Overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
    {
        data = copy.data;
        firstValue = copy.firstValue;
    }
    return (*this);
}
// Load data from data.csv into a map
void BitcoinExchange::loadData()
{
    // Open data.csv
    std::ifstream file("data/data.csv");
    // Check if file is open
    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    // Read file line by line
    std::string line;

    std::getline(file, line); // Skip first line
    while (std::getline(file, line))
    {
        while (line.empty()) // Skip empty lines
            std::getline(file, line);
        try
        {
            int key = validIntKey(line, ",");
            double value = validValue(line, ",");
            // Insert key(date) and value into map
            data.insert(std::pair<int, double>(key, value));
            // Find the first available date in the map(data.csv)
            if (firstValue == 0 || key < firstValue)
                firstValue = key;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            continue ; // Skip invalid data
        }
    }
}
// Print exchange rates for each date in the file
void BitcoinExchange::printExchangeRates(const std::string &file) const
{
    // Open file
    std::ifstream input(file.c_str());
    // Check if file is open
    if (!input.is_open())
        throw std::runtime_error("Could not open file");
    // Read file line by line
    std::string line;

    std::getline(input, line); // Skip first line
    while (getline(input, line))
    {
        try
        {
            // Skip empty lines
            while (line.empty())
            {
                std::getline(input, line);
                std::cout << std::endl;
            }
            // Extract key and value from line
            // Convert key(date) to an integer for map
            int key = validIntKey(line, "|");
            // Convert key(date) to a string for output
            std::string keyPart = line.substr(0, line.find("|"));
            // Trim whitespace from key(date) string
            trimFrontBack(keyPart);
            // Convert value to a floating-point number
            double value = validValue(line, "|");
            // Find key(date) in map
            std::map<int, double>::const_iterator it = data.find(key);
            // If key(date) is not found, decrement key(date) by 1 and try again
            // firstValue is the first available date in the map(data.csv)
            while (it == data.end() && key > firstValue)
            {
                // Decrement key
                --key;
                // Reassign it to the new key
                it = data.find(key);
            }
            // If key(date) is found, print the exchange rate
            if (it != data.end())
            {
                std::cout << keyPart << " => " << value << "(" << it->second << ")" << " = " << (value * it->second) << std::endl;
            }
            // If key(date) is not found or date is before the first date in the map, print an error message
            else
            {
                std::cout << "Error: no data for " << keyPart << std::endl;
            }
        }
        // Catch any exception thrown by validKey() or validValue()
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}
// Create a valid key(date) for the map
int BitcoinExchange::validIntKey(const std::string &key, const std::string &delim) const
{
    // Find the position of the delimiter
    size_t findPos = key.find(delim);
    // Check if the delimiter exists, if not, throw an exception
    if (findPos == std::string::npos)
        throw std::runtime_error("Error: no delimiter. => " + key);
    // Extract key(date) from line using .substr() and .find() functions
    std::string keyPart = key.substr(0, key.find(delim));
    // Trim whitespace from key(date) string
    trimFrontBack(keyPart);
    // Check if the keyPart is empty
    if (keyPart.empty())
        throw std::runtime_error("Error: no key.");
    // Check Date Format
    if (checkDateFormat(keyPart) == false)
        throw std::runtime_error("Invalid Date Format: YYYY-MM-DD => " + keyPart);

    // Manual check for valid date format for detailed error messages
    if (keyPart[4] != '-' || keyPart[7] != '-')
        throw std::runtime_error("Invalid Date Format: YYYY-MM-DD => " + keyPart);

    // Extract Year, Month, and Day
    std::string year = keyPart.substr(0, 4);
    std::string month = keyPart.substr(5, 2);
    std::string day = keyPart.substr(8, 2);

    // Manual Check for valid date format
    if (year.length() != 4 || month.length() != 2 || day.length() != 2)
        throw std::runtime_error("Invalid Date Format: YYYY-MM-DD => " + keyPart);

    // Convert Dates to Integers
    int yearInt = std::atoi(year.c_str());
    int monthInt = std::atoi(month.c_str());
    int dayInt = std::atoi(day.c_str());

    // Check for valid year
    if (yearInt < 2009)
        throw std::runtime_error("Invlid Year: 2009 - Current Year => " + keyPart);

    // Check for valid month
    if (monthInt < 1 || monthInt > 12)
        throw std::runtime_error("Invalid Month: 1 - 12 => " + keyPart);

    // Check for specific month-day combinations with 31 days
    if (dayInt < 1 || dayInt > 31)
        throw std::runtime_error("Invalid Day: 1 - 31 for months with 31 days => " + keyPart);

    // Check for specific month-day combinations with fewer than 31 days
    if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
        throw std::runtime_error("Invalid Day: 1 - 30 for months with 30 days => " + keyPart);

    // Check for February
    if (monthInt == 2) {
        // Check for February with leap year consideration
        if ((yearInt % 4 == 0 && yearInt % 100 != 0) || (yearInt % 400 == 0))
        {
            if (dayInt > 29)
                throw std::runtime_error("Invalid Day: 1 - 29 for February in a leap year => " + keyPart);
        }
        else
        {
            if (dayInt > 28)
                throw std::runtime_error("Invalid Day: 1 - 28 for February in a non-leap year => " + keyPart);
        }
    }
    // Convert key(date) to an integer
    int keyInt = yearInt * 10000 + monthInt * 100 + dayInt;
    // Check if key(date) is in the future
    int currentDate = (getTime()->tm_year + 1900) * 10000 + (getTime()->tm_mon + 1) * 100 + getTime()->tm_mday;
    if (keyInt > currentDate)
        throw std::runtime_error("Invalid Date: Date cannot be in the future => " + keyPart);
    // Return key(date) if valid.
    return (keyInt);
}
// Create a valid value for the map
double BitcoinExchange::validValue(const std::string &value, const std::string &delim) const
{
    // Find the position of the delimiter
    size_t findPos = value.find(delim);
    // Check if the delimiter exists
    if (findPos == std::string::npos)
        throw std::runtime_error("Error: no delimiter.");
    // Extract value from line using .substr() and .find() functions
    std::string valuePart = value.substr(value.find(delim) + 1);
    // Trim whitespace from value
    trimFrontBack(valuePart);
    // Check if the valuePart is empty
    if (valuePart.empty())
        throw std::runtime_error("Error: no value.");
    // Check if the valuePart contains only digits and a decimal point (also allows for negative numbers for error messages)
    if (valuePart.find_first_not_of("0123456789-.") != std::string::npos)
        throw std::runtime_error("Error: value is not a number.");
    if (isNumber(valuePart) == false)
        throw std::runtime_error("Error: value is not a number.");
    // Convert value to a floating-point number
    double floatValue = strtof(valuePart.c_str(), NULL);

    // Check if the value is negative or greater than 1000 when the delimiter is "|"
    if (floatValue < 0)
        throw std::runtime_error("Error: not a positive number.");
    else if (delim == "|" && floatValue > 1000)
        throw std::runtime_error("Error: too large a number.");
    // Return value if valid
    return (floatValue);
}
// Auto check for valid date format
bool    BitcoinExchange::checkDateFormat(const std::string &date) const
{
    // Format: YYYY-MM-DD
    const char  *format = "%Y-%m-%d";
    // Create a tm struct
    struct  tm   tm;

    // strptime() returns NULL if the date is invalid or empty
    if (strptime(date.c_str(), format, &tm) == NULL)
        return (false);
    // Check if the date is empty or not 10 characters long
    if (date.empty() || (date.size() != 10))
        return (false);
    return (true);
}
// Trim whitespace from the front and back of a string
void    BitcoinExchange::trimFrontBack(std::string &s) const
{
    // Erase whitespace from the front
    s.erase(s.find_last_not_of(' ') + 1);
    // Erase whitespace from the back
    s.erase(0, s.find_first_not_of(' '));
}
// Get the current time
struct tm *BitcoinExchange::getTime() const
{
    // currentTime is the current time in seconds
    time_t      currentTime;
    // timeInfo is a pointer to a tm struct
    struct tm   *timeInfo;

    // Get the current time in seconds. time() returns -1 if it fails
    if (time(&currentTime) == -1)
        throw std::runtime_error("Error: could not get current time.");
    // Convert the current time to a tm struct. localtime() returns NULL if it fails
    timeInfo = localtime(&currentTime);
    if (timeInfo == NULL)
        throw std::runtime_error("Error: could not convert current time to tm struct.");
    // Return a pointer to the tm struct
    return (timeInfo);
}

bool isNumber(const std::string &s)
{
    int dotCount = 0;
    int signCount = 0;
    
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '-' || s[i] == '+')
            signCount++;
        if (s[i] == '.')
            dotCount++;
        if (s[i] != '-' && s[i] != '+' && s[i] != '.' && !isdigit(s[i]))
            return (false);
    }
    if (dotCount > 1 || signCount > 1)
        return (false);
    return (true);
}