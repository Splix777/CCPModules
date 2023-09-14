/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:52:46 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/14 12:29:11 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;

		Fixed c;

		// for (int i = 0; i < 257; i++)
		// {
		// 	std::cout << c << std::endl;
		// 	c++;
		// }
		std::cout << Fixed::max( a, c ) << std::endl;
		std::cout << Fixed::min( a, c ) << std::endl;
		std::cout << "A is bigger than C? " << (a > c) << std::endl;
		std::cout << "A is smaller than C? " << (a < c) << std::endl;
		std::cout << a + c << std::endl;
	}
	std::cout << std::endl;
	{
		Fixed a;
		a.setRawBits(-1);
		Fixed const b( Fixed( -5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;

		Fixed c;

		// for (int i = 0; i < 257; i++)
		// {
		// 	std::cout << c << std::endl;
		// 	c++;
		// }
		std::cout << Fixed::max( a, c ) << std::endl;
		std::cout << Fixed::min( a, c ) << std::endl;
		std::cout << "A is bigger than C? " << (a > c) << std::endl;
		std::cout << "A is smaller than C? " << (a < c) << std::endl;
		std::cout << a + c << std::endl;
	}
	return (0);
}

/*
Let's walk through what's happening:

1. a is initially set to 0.

2. You use the a++ operator, which calls Fixed::operator++(int num)
with num as 1.

3. Inside Fixed::operator++(int num), _fpn (0) is incremented
by 1 using integer addition. This results in _fpn becoming 1.

4. The original value of _fpn (0) is returned from the operator.

This is why you see the value 0.00390625 when you print a after
using the a++ operator. It's due to the division by
(1 << fractional_bits) in your toFloat() function, which
converts the integer _fpn value to its fixed-pointrepresentation.
----------------------------------------------------
Let's break down what (1 << fractional_bits) does:

1. 1 is a binary number with all bits set to 0 except the rightmost
bit, which is 1: 00000001 in binary.

2. << is the bitwise left shift operator. It shifts the bits of
a binary number to the left by a specified number of positions.

3. fractional_bits is a constant value representing the number of
fractional bits in your fixed-point representation. Let's say
it's 8.

So, when you calculate (1 << fractional_bits), you are shifting
the binary representation of 1 to the left by 8 positions:
00000001 << 8 = 0000000100000000
-----------------------------------------------------
Using 8 fractional bits to represent the fractional part of
the fixed-point number. This means that each increment of
_fpn by 1 will actually represent an increase of 1 / 256,
which is approximately 0.00390625.

So, to reach an integer value of 1 in your fixed-point
representation, you would need to perform approximately
256 increments using a++, each increment increasing the
value of _fpn by 0.00390625. This is because 256 increments
of 0.00390625 sum up to 1:

*/