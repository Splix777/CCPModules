/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:04:17 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/18 18:05:20 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
// Prints Square of a number
static void printSquare(int num)
{
    std::cout << num * num << " ";
}
// Prints Double of a number
static void printDouble(double num)
{
    std::cout << num * 2 << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    int emptyArray[] = {};

    iter(intArray, 5, printSquare);
    std::cout << std::endl;
    
    iter(doubleArray, 5, printDouble);
    std::cout << std::endl;

    iter(charArray, 5, printDouble);
    std::cout << std::endl;

    iter(emptyArray, 0, printDouble);
    std::cout << std::endl;

    return 0;
}
