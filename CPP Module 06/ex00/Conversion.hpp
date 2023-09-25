/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:02:31 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/25 17:21:56 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <string>
# include <math.h>
# include <climits>

// Enum to determine the type of the literal
typedef enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL_F,
    SPECIAL_D,
    ERROR,
}   e_type;

class ScalarConverter
{
    private:
        // Copy constructor
        ScalarConverter(const ScalarConverter &copy);
        // Operator overloads
        ScalarConverter &operator=(const ScalarConverter &copy);
        // Member functions
        static int  determineType(const std::string &literal);
        static bool isInt(const std::string &literal);
        static bool isFloat(const std::string &literal);
        static bool isDouble(const std::string &literal);
        // Constructors and destructor (private to prevent stack allocation)
        ScalarConverter();
        ~ScalarConverter();

    public:
        // Static method for conversion
        static void convert(const std::string &literal);
};

void    printChar(const std::string &literal);
void    printInt(const std::string &literal);
void    printFloat(const std::string &literal);
void    printDouble(const std::string &literal);
void    printSpecialF(const std::string &literal);
void    printSpecialD(const std::string &literal);
void    printUnknown(const std::string &literal);

#endif