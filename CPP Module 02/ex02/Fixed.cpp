/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:52:40 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:54:03 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fpn(0) // Default constructor initializes the fixed-point number to 0.
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    //std::cout << "Int constructor called" << std::endl;
    _fpn = num * (1 << fractional_bits);
}

Fixed::Fixed(const float num)
{
    //std::cout << "Float constructor called" << std::endl;
    _fpn = roundf(num * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &other) : _fpn(other._fpn) // Copy constructor copies the value from another object.
{
    //std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const // Member function to get the raw value of the fixed-point number.
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (_fpn);
}

void Fixed::setRawBits(int const raw)
{
    if (raw >= 0) // Adding a basic validation check
    {
        //std::cout << "setRawBits member function called" << std::endl;
        _fpn = raw;
    }
    else
    {
        std::cerr << "Error: Cannot set raw bits with a negative value" << std::endl;
    }
}

float   Fixed::toFloat( void ) const
{
    //std::cout << "toFloat member function called" << std::endl;
    return (static_cast<float>(_fpn) / (1 << fractional_bits));
}

int     Fixed::toInt( void ) const
{
    //std::cout << "toInt member function called" << std::endl;
    return (_fpn / (1 << fractional_bits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this == &other) // Check for self-assignment
        return (*this);

    _fpn = other._fpn;
    return (*this);
}

bool Fixed::operator>(const Fixed& other) const
{
    return (_fpn > other._fpn);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (_fpn < other._fpn);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (_fpn >= other._fpn);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (_fpn <= other._fpn);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (_fpn == other._fpn);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (_fpn != other._fpn);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (this->toFloat() / other.toFloat());
}

Fixed   &Fixed::operator++()
{
    _fpn += 1;
    return (*this);
}

Fixed Fixed::operator++(int num)
{
    Fixed temp(*this);

    if (!num)
        _fpn += 1;
    else
        _fpn += num;
    return (temp);
}

Fixed   &Fixed::operator--()
{
    _fpn -= 1;
    return (*this);
}

Fixed Fixed::operator--(int num)
{
    Fixed temp(*this);

    if (!num)
        _fpn -= 1;
    else
        _fpn -= num;
    return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

std::ostream &operator<<(std::ostream& out, const Fixed& fixed)
{
    return (out << fixed.toFloat());
}