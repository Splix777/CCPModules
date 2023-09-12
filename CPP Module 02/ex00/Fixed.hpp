/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:52:01 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:52:12 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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