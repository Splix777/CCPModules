#include "Conversion.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter was created" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter was destroyed" << std::endl;
}

int ScalarConverter::determineType(const std::string &literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return (SPECIAL_F);
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return (SPECIAL_D);
    if (isInt(literal))
        return (INT);
    if (isFloat(literal))
        return (FLOAT);
    if (isDouble(literal))
        return (DOUBLE);
    if (literal.length() == 1)
        return (CHAR);
    return (ERROR);
}

bool    ScalarConverter::isInt(const std::string &literal)
{
    for (size_t i = 0; i < literal.length(); i++)
    {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
            continue;
        if (!isdigit(literal[i]))
            return (false);
    }
    return (true);
}

bool    ScalarConverter::isDouble(const std::string &literal)
{
    int dot = 0;
    for (size_t i = 0; i < literal.length(); i++)
    {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
            continue;
        if (literal[i] == '.')
            dot++;
        else if (!isdigit(literal[i]))
            return (false);
    }
    if (dot == 1)
        return (true);
    return (false);
}

bool    ScalarConverter::isFloat(const std::string &literal)
{
    int dot = 0;
    if (literal[literal.length() - 1] != 'f')
        return (false);
    for (size_t i = 0; i < literal.length() - 1; i++)
    {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
            continue;
        if (literal[i] == '.')
            dot++;
        else if (!isdigit(literal[i]))
            return (false);
    }
    if (dot == 1)
        return (true);
    return (false);
}

void    ScalarConverter::convert(const std::string &literal)
{
    int type = determineType(literal);
    if (type == CHAR)
        printChar(literal);
    else if (type == INT)
        printInt(literal);
    else if (type == FLOAT)
        printFloat(literal);
    else if (type == DOUBLE)
        printDouble(literal);
    else if (type == SPECIAL_F)
        printSpecialF(literal);
    else if (type == SPECIAL_D)
        printSpecialD(literal);
    else if (type == ERROR)
        printUnkown(literal);
}

void    printChar(const std::string &literal)
{
    int i = static_cast<int>(literal[0]);
    float f = static_cast<float>(literal[0]);
    double d = static_cast<double>(literal[0]);

    std::cout << "Char Detected:" << std::endl;

    if (isprint(i))
        std::cout << "char: '" << literal[0] << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (i > 2147483647.0)
        std::cout << "int: Overflow" << std::endl;
    else if (i < -2147483648.0)
        std::cout << "int: Underflow" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout.precision(10);
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;
}

void    printInt(const std::string &literal)
{
    double d = static_cast<double>(strtod(literal.c_str(), NULL));
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);


    std::cout << "Int Detected:" << std::endl;

    if (isprint(i))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (i > 2147483647.0)
        std::cout << "int: Overflow" << std::endl;
    else if (i < -2147483648.0)
        std::cout << "int: Underflow" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;
}

void    printFloat(const std::string &literal)
{
    double d = static_cast<double>(strtod(literal.c_str(), NULL));
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    std::cout << "Float Detected:" << std::endl;

    if (isprint(i))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (i > 2147483647.0)
        std::cout << "int: Overflow" << std::endl;
    else if (i < -2147483648.0)
        std::cout << "int: Underflow" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout.precision(10);
    if (f - floorf(f) == 0)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (d - floor(d) == 0)
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void    printDouble(const std::string &literal)
{
    double d = static_cast<double>(strtod(literal.c_str(), NULL));
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    std::cout << "Double Detected:" << std::endl;

    if (isprint(i))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (i > 2147483647.0)
        std::cout << "int: Overflow" << std::endl;
    else if (i < -2147483648.0)
        std::cout << "int: Underflow" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout.precision(10);
    if (f - floorf(f) == 0)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (d - floor(d) == 0)
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void    printSpecialF(const std::string &literal)
{
	std::cout << "char:\t Impossible"     << std::endl;
	std::cout << "int:\t Impossible"      << std::endl;
	std::cout << "float:\t "              << literal << std::endl;
	std::cout << "double:\t "             << literal.substr(0, literal.length() - 1) << std::endl;    
}

void    printSpecialD(const std::string &literal)
{
	std::cout << "char:\t Impossible"     << std::endl;
	std::cout << "int:\t Impossible"      << std::endl;
	std::cout << "float:\t "              << literal + "f" << std::endl;
	std::cout << "double:\t "             << literal << std::endl;    
}

void    printUnkown(const std::string &literal)
{
    std::cout << "Unkown type: " << literal <<std::endl;
}
