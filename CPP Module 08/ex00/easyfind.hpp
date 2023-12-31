/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:04:42 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/26 17:46:12 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>     // cout, endl
#include <algorithm>    // find
#include <iterator>     // distance
#include <exception>    // exception
#include <vector>       // vector
#include <list>         // list
#include <deque>        // deque

// Define a custom exception class called NotFound that inherits from std::exception
class NotFound : std::exception
{
public:
    // Override the what() function to return a description of the exception
    virtual const char *what() const throw()
    {
        return ("Not Found");
    }
};

// Define a function template named easyfind
// This function takes a container 'input' of type T and an integer 'i'
template <typename T>
void easyfind(T &input, int i)
{
    // Declare an iterator of type typename T::iterator (dependent on the container's type)
    // Use the find algorithm to search for 'i' in the 'input' container
    // The find function returns an iterator pointing to the first occurrence of 'i'
    typename T::iterator it = find(input.begin(), input.end(), i);

    // If the iterator points to the end of the container, it means 'i' was not found
    if (it == input.end())
        // Throw the NotFound exception
        throw (NotFound());
    else
        std::cout << "Value " << i << " found in container at index " << std::distance(input.begin(), it) << std::endl;
}

/*
Explanation of typename and Templates:

In C++, templates allow you to define functions and classes that work with different types.
However, when using dependent types (like T::iterator), the compiler doesn't know what
the type is until the template is instantiated. The typename keyword is used to tell
the compiler that T::iterator is a type, not a variable or a function.

For example, consider typename T::iterator it;. Here, T::iterator is a dependent name,
and using typename helps the compiler understand that iterator is a nested type within
the template type T.

In summary, templates enable you to write code that is generic and works with various
types. The typename keyword is used to disambiguate dependent types within template
code, ensuring correct compilation even when the actual type is not known until instantiation.
*/