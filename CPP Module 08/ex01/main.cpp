/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:04:51 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/26 18:14:14 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    try
    {
        // Test constructors, addNumber, shortestSpan, and longestSpan
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        sp.printVector();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        std::cout << std::endl;

        // Test copy constructor and operator overloads
        std::cout << "Testing copy constructor and operator overloads" << std::endl;
        Span spCopy(sp);
        spCopy.printVector();
        std::cout << "Address of original span: " << &sp << std::endl;
        std::cout << "Address of copied span: " << &spCopy << std::endl;
        std::cout << std::endl;
        Span spAssigned;
        spAssigned = spCopy;
        spAssigned.printVector();
        std::cout << "Address of original span: " << &spCopy << std::endl;
        std::cout << "Address of assigned span: " << &spAssigned << std::endl;
        std::cout << std::endl;
        
        // Test filling a large span and checking spans
        std::cout << "Testing filling a large span and checking spans" << std::endl;
        Span sp1 = Span(1000000);
        sp1.fill();
        // sp1.printVector();
        std::cout << "Shortest span (large span): " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest span (large span): " << sp1.longestSpan() << std::endl;
        std::cout << std::endl;

        
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
