/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:04:45 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/26 17:53:06 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    try
    {
        // Test with std::vector
        std::vector<int> vec;
        // Fill the vector with values 0, 2, 4, 6, 8
        std::cout << "Vector: ";
        for (int i = 0; i < 5; ++i)
        {
            vec.push_back(i * 2);
            std::cout << vec[i] << ' ';
        }
        std::cout << std::endl;
        // Find the value 4 in the vector
        int valueToFind = 4;
        std::cout << "Value to find: " << valueToFind << std::endl;
        // Call the easyfind function template to find the value
        easyfind(vec, valueToFind);

        // Test with std::list (same as vector) to show that the function works with other containers
        std::list<int> myList;
        std::cout << "List: ";
        for (int i = 0; i < 5; ++i)
        {
            myList.push_back(i * 3);
            std::cout << myList.back() << ' ';
        }
        std::cout << std::endl;

        valueToFind = 9;
        std::cout << "Value to find: " << valueToFind << std::endl;
        easyfind(myList, valueToFind);

        // Test with std::deque (same as vector) to show that the function works with other containers
        std::deque<int> myDeque;
        std::cout << "Deque: ";
        for (int i = 0; i < 5; ++i)
        {
            myDeque.push_back(i * 4);
            std::cout << myDeque.back() << ' ';
        }
        std::cout << std::endl;
        // We search for the value 15 which is not in the deque, so the function should throw an exception.
        valueToFind = 12;
        std::cout << "Value to find: " << valueToFind << std::endl;
        easyfind(myDeque, valueToFind);

        // Test with an empty container
        std::deque<int> emptyDeque;
        std::cout << "Empty deque:  " << std::endl;
        valueToFind = 0;
        std::cout << "Value to find: " << valueToFind << std::endl;
        easyfind(emptyDeque, valueToFind);
    }
    catch (const NotFound& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
