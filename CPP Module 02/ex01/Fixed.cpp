/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:52:23 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/14 12:22:38 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fpn(0) // Default constructor initializes the fixed-point number to 0
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    _fpn = num * (1 << fractional_bits);
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    _fpn = roundf(num * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed& other) : _fpn(other._fpn) // Copy constructor copies the value from another object.
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed   &Fixed::operator=(const Fixed& other) // Copy assignment operator overload.
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other) // Check for self-assignment
        return (*this);

    _fpn = other._fpn;
    return (*this);
}

int Fixed::getRawBits() const // Member function to get the raw value of the fixed-point number.
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fpn);
}

void Fixed::setRawBits(int const raw)
{

    std::cout << "setRawBits member function called" << std::endl;
    _fpn = raw;
}

float   Fixed::toFloat( void ) const
{
    return (static_cast<float>(_fpn) / (1 << fractional_bits));
}

int     Fixed::toInt( void ) const
{
    return (_fpn / (1 << fractional_bits));
}

std::ostream    &operator<<(std::ostream &out, const Fixed &fixed)
{
    return (out << fixed.toFloat());
}