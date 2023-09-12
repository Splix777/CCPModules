/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:04:10 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:04:11 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Define a guard to prevent multiple inclusion of the header
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// Include necessary headers for the template functions
# include <iostream>    // std::cout
# include <string>      // std::string

// Define a template function to swap two values
template <typename T>
void swap(T &a, T &b)
{
    // Create a temporary variable to hold one of the values
    T temp;
    temp = a;
    
    // Swap the values
    a = b;
    b = temp;
}

// Define a template function to find the minimum of two values
template <typename A>
A min(A &a, A &b)
{
    // Compare the values and return the smaller one
    // If the values are equal, return the second value
    if (a < b)
        return a;
    return b;
}

// Define a template function to find the maximum of two values
template <typename X>
X max(X &a, X &b)
{
    // Compare the values and return the larger one
    // If the values are equal, return the second value
    if (a > b)
        return a;
    return b;
}
// End of the guard to prevent multiple inclusion
#endif
