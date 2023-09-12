/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:52:26 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:52:35 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
    int _fpn; // Fixed-point number
    static const int fractional_bits = 8;
public:
    // Default constructor
    Fixed();
    // Destructor
    ~Fixed();
    // Copy constructor
    Fixed(const Fixed &other);
    // Parameterized constructor
    Fixed(const int num);
    Fixed(const float num);
    // Operator overloads
    Fixed   &operator=(const Fixed& other);
    // Member functions
    float   toFloat( void ) const;
    int     toInt( void ) const;
    // Getters and setters
    int     getRawBits( void ) const;
    void    setRawBits( int const raw);
};

std::ostream    &operator<<(std::ostream& out, const Fixed &fixed);

#endif