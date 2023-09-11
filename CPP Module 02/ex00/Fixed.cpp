#include "Fixed.hpp"

Fixed::Fixed(void): _fpn(0) // Default constructor initializes the fixed-point number to 0
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fpn(other._fpn) // Copy constructor copies the value from another object.
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) // Copy assignment operator overload.
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other) // Check for self-assignment
        return (*this);

    _fpn = other._fpn;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const // Member function to get the raw value of the fixed-point number.
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fpn);
}

void Fixed::setRawBits(int const raw)
{
    if (raw >= 0) // Adding a basic validation check
    {
        std::cout << "setRawBits member function called" << std::endl;
        _fpn = raw;
    }
    else
    {
        std::cerr << "Error: Cannot set raw bits with a negative value" << std::endl;
    }
}