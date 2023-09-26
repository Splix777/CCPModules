/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:05:08 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/26 18:12:31 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>

class Span
{
    private:
        // Vector Container - Used a vector because it is a dynamic container that can be resized and is faster than a list for random access.
        std::vector<int>    vector;
        // Attributes
        unsigned int        size;
    
    public:
        // Constructor
        Span();
        Span(unsigned int N);
        Span(Span const &copy);
        // Operator Overload
        Span &operator=(Span const &copy);
        // Deconstructor
        ~Span();
        // Member Functions
        void            addNumber(int number);
        void            fill(void);
        unsigned int    shortestSpan() const;
        unsigned int    longestSpan() const;
        // Getters
        unsigned int    getSize() const;
        void            printVector() const;
        // Exceptions
        class   ContainerFull : public std::exception
        {
            public:
                char const *what() const throw()
                {
                    return "Vector is already full!";
                }
        };
        class   ContainerEmpty : public std::exception
        {
            public:
                char const *what() const throw()
                {
                    return "Vector is empty!";
                }
        };
        class   ContainerOnlyOne : public std::exception
        {
            public:
                char const *what() const throw()
                {
                    return "Vector only has one number!";
                }
        };
};