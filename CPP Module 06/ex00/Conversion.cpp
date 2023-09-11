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
        printUnknown(literal);
}

/*
Description:
    static_cast is one of the C++ casting operators used to explicitly convert
    one data type into another. It is a versatile and flexible way to perform type
    conversions in a controlled manner. Here's a thorough explanation of static_cast,
    its functionality, and its various uses:

    1.  Purpose of static_cast: static_cast is primarily used to convert between
        related data types in a safe and explicit manner. It is used when the conversion
        is well-defined and should not result in information loss. Unlike some other
        casting operators, static_cast is checked at compile-time, which means the
        compiler ensures the safety of the conversion whenever possible.

    2.  How static_cast Works: When you use static_cast, you provide the desired target
        data type in angle brackets, like this: static_cast<target_type>(expression).
        The expression is the value or variable you want to convert.

    3.  Usage in the Program: In the provided program, static_cast is used to convert
        characters to different numeric data types (int, float, double) for further
        processing and display. For example, static_cast<int>(literal[0]) converts
        the first character of the literal string to an integer. This ensures that the
        character is treated as a numeric value.

    4.  When to Use static_cast: static_cast is used when you want to convert between
        related data types in a safe and explicit manner. It is used when the conversion
        is well-defined and should not result in information loss. Unlike some other
        casting operators, static_cast is checked at compile-time, which means the
        compiler ensures the safety of the conversion whenever possible.

    5.  Different Uses of static_cast:

        -   Converting between numeric data types: static_cast is used to convert between
            numeric data types, such as int, float, and double. For example, static_cast<int>(3.14)
            converts the floating-point value 3.14 to an integer. This is a safe conversion
            because the value is truncated to 3, which is a valid integer value.
        
        -   Converting between pointers: static_cast is used to convert between pointers
            to related classes. For example, static_cast<Derived*>(base_ptr) converts a
            pointer to a base class to a pointer to a derived class. This is a safe conversion
            because the derived class is a specialization of the base class, so the conversion
            is well-defined.

        -   Converting between pointers and integers: static_cast is used to convert between
            pointers and integers. For example, static_cast<int>(ptr) converts a pointer to
            an integer. This is a safe conversion because the pointer is converted to an integer
            value that represents the memory address of the pointer.
        
        -   Converting between pointers and booleans: static_cast is used to convert between
            pointers and booleans. For example, static_cast<bool>(ptr) converts a pointer to
            a boolean value. This is a safe conversion because the pointer is converted to a
            boolean value that represents whether the pointer is null or not.

        -   Converting between pointers to functions: static_cast is used to convert between
            pointers to functions. For example, static_cast<void(*)()>(func_ptr) converts a
            pointer to a function to a pointer to a void function. This is a safe conversion
            because the function pointer is converted to a void function pointer, which is
            a valid conversion.

        -   Converting between pointers to member functions: static_cast is used to convert
            between pointers to member functions. For example, static_cast<void(Base::*)()>(func_ptr)
            converts a pointer to a member function of the Base class to a pointer to a void
            member function of the Base class. This is a safe conversion because the member
            function pointer is converted to a void member function pointer, which is a valid
            conversion.

        -   Converting between pointers to member objects: static_cast is used to convert
            between pointers to member objects. For example, static_cast<int(Base::*)>(obj_ptr)
            converts a pointer to a member object of the Base class to a pointer to an integer
            member object of the Base class. This is a safe conversion because the member object
            pointer is converted to an integer member object pointer, which is a valid conversion.

In summary, static_cast is a versatile C++ casting operator that provides a way to explicitly
control type conversions. It is used to ensure type safety, perform well-defined conversions,
and handle various scenarios where type-related adjustments are necessary. Its compile-time
checking makes it a preferred choice for many type conversion tasks in C++.  
*/

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

/*
   Explanation of std::cout.precision(10):

   1. What std::cout.precision(10) Does:

      - std::cout: The standard output stream in C++, used for displaying text and data.
      - .precision(10): A member function of std::cout used to set the precision
        (number of decimal places) for floating-point numbers when printed.

   2. How It Works:

      - When you set the precision using std::cout.precision(), it affects how
        floating-point numbers are formatted when printed with std::cout.
      - std::cout.precision(10) sets the precision to 10 decimal places. It means that
        floating-point numbers printed with std::cout will display up to 10 decimal places.

   3. Why It's Used Here:

      - In the provided printChar function, after converting a character to float and
        double (which may involve truncation or rounding), std::cout.precision(10) is used.
      - This ensures that the converted floating-point values are printed with sufficient
        precision to represent their actual values.
      - Setting the precision to 10 is a good practice for maintaining accuracy when
        working with floating-point numbers, especially in scientific or engineering calculations.

   -    Note: For integers, which have no decimal places, setting the precision has no
        effect on the printed output.

   Example Usage:
   std::cout.precision(10); // Set precision to 10 decimal places for floating-point numbers.
*/

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

/*
   Explanation of floorf and floor in the printFloat/printDouble function:

   1. floorf Function:

      - floorf is a mathematical function provided by the C and C++ standard libraries.
      - It takes a single argument, a floating-point number (typically of type float),
        and returns the largest integer value that is less than or equal to the input number.
      - Example: floorf(3.7f) returns 3.0f.

   2. floor Function:

      - floor is similar to floorf but operates on double-precision floating-point
        numbers (typically of type double).
      - It takes a single argument, a double-precision floating-point number, and
        returns the largest integer value that is less than or equal to the input number.
      - Example: floor(3.7) returns 3.0.

   How They Are Used in the printFloat/printDouble Function:

   - float f = static_cast<float>(d);: Converts a double value d to a float value f.
   - if (f - floorf(f) == 0): Checks if f minus its integer part (obtained using floorf(f))
     is equal to zero to determine whether f has a fractional part or is a whole number (integer).
   - if (d - floor(d) == 0): Similar to the previous line, checks whether d has a fractional part
     or is a whole number.
   - Depending on whether f or d is a whole number or has a fractional part, the output is
     formatted accordingly. If the number is a whole number, ".0f" or ".0" is added to indicate
     that it's an integer value.

   Example Usage:
   float f = 5.5f;
   if (f - floorf(f) == 0)
       std::cout << "float: " << f << ".0f" << std::endl; // Output: "float: 5.5f"
   else
       std::cout << "float: " << f << "f" << std::endl;    // Output: "float: 5.5f"
*/

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

void    printUnknown(const std::string &literal)
{
    std::cout << "Unknown type: " << literal <<std::endl;
}
