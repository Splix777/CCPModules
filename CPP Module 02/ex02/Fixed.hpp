/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:52:43 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:52:51 by fsalazar         ###   ########.fr       */
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
    // Constructors
    Fixed( void );
    Fixed(const Fixed &other);
    Fixed(const int num);
    Fixed(const float num);
    // Deconstructor
    ~Fixed();
    // Conversion Functions
    int     toInt(void) const;
    float   toFloat(void) const;
    // Getter/Setter Functions
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    // Assignment Operator Overload
    Fixed   &operator=(const Fixed &other);
    // Comparison Operator Overloads
    bool    operator>(const Fixed &other) const;
    bool    operator<(const Fixed &other) const;
    bool    operator>=(const Fixed &other) const;
    bool    operator<=(const Fixed &other) const;
    bool    operator==(const Fixed &other) const;
    bool    operator!=(const Fixed &other) const;
    // Arithmetic Operator Overloads
    Fixed   operator+(const Fixed &other) const;
    Fixed   operator-(const Fixed &other) const;
    Fixed   operator*(const Fixed &other) const;
    Fixed   operator/(const Fixed &other) const;
    // Increment/Decrement Operator
    Fixed   &operator++(void);
    Fixed   operator++(int num);
    Fixed   &operator--(void);
    Fixed   operator--(int num);
    // Min/Max Overload Functions
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(Fixed const &a, Fixed const &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(Fixed const &a, Fixed const &b);
};
std::ostream &operator<<(std::ostream& out, const Fixed& fixed);

#endif