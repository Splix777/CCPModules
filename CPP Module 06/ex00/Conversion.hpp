#pragma once
#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <string>
# include <math.h>

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

    public:
        // Constructors and destructor
        ScalarConverter();
        ~ScalarConverter();
        // Static method for conversion
        static void convert(const std::string &literal);
        // Exceptions
        class ImpossibleException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("impossible");
            }
        };
        class NonDisplayableException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("Non displayable");
            }
        };
};

void    printChar(const std::string &literal);
void    printInt(const std::string &literal);
void    printFloat(const std::string &literal);
void    printDouble(const std::string &literal);
void    printSpecialF(const std::string &literal);
void    printSpecialD(const std::string &literal);
void    printUnkown(const std::string &literal);

#endif