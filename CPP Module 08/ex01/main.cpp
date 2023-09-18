/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:04:51 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/18 18:28:30 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    try
    {
        // Test constructors, addNumber, shortestSpan, and longestSpan
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        // Remove comment to test Vector Full.
        // sp.addNumber(12);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Test copy constructor and operator overloads
        Span spCopy(sp);
        Span spAssigned;
        spAssigned = spCopy;
        
        // Test filling a large span and checking spans
        Span sp1 = Span(1000000);
        sp1.fill();
        std::cout << "Shortest span (large span): " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest span (large span): " << sp1.longestSpan() << std::endl;

        // Test exceptions Empty
        // This should throw ContainerEmpty exception
        // Span emptySpan = Span(0);
        // emptySpan.shortestSpan();
        
        // Test exceptions Only One
        // This should throw ContainerOnlyOne exception
        // Span oneSpan = Span(1);
        // oneSpan.addNumber(42);
        // oneSpan.shortestSpan();
        
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}
