#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int _fpn; // Fixed-point number
    static const int fractional_bits = 8;
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed   &operator=(const Fixed &other);
    int     getRawBits( void ) const;
    void    setRawBits( int const raw);
};

#endif