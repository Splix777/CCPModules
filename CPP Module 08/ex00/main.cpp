/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:04:45 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/18 18:21:59 by fsalazar         ###   ########.fr       */
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
        for (int i = 0; i < 5; ++i)
            vec.push_back(i * 2);
        // Find the value 4 in the vector
        int valueToFind = 4;
        // Call the easyfind function template to find the value
        std::vector<int>::iterator result = easyfind(vec, valueToFind);
        // If the iterator returned by easyfind is not the end of the vector, the value was found
        if (result != vec.end())
            std::cout << "Value " << valueToFind << " found in vector at index " << std::distance(vec.begin(), result) << std::endl;
            /*
            *   std::distance returns the distance between two iterators.
            *   The first argument is the iterator to the first element of the container.
            *   The second argument is the result iterator returned by easyfind.
            */
        else
            std::cout << "Value " << valueToFind << " not found in vector." << std::endl;

        // Test with std::list (same as vector) to show that the function works with other containers
        std::list<int> myList;
        for (int i = 0; i < 5; ++i)
            myList.push_back(i * 3);

        valueToFind = 9;
        std::list<int>::iterator listResult = easyfind(myList, valueToFind);
        if (listResult != myList.end())
            std::cout << "Value " << valueToFind << " found in list at position " << std::distance(myList.begin(), listResult) << std::endl;
        else
            std::cout << "Value " << valueToFind << " not found in list." << std::endl;

        // Test with std::deque (same as vector) to show that the function works with other containers
        std::deque<int> myDeque;
        for (int i = 0; i < 5; ++i)
            myDeque.push_back(i * 4);
        // We search for the value 15 which is not in the deque, so the function should throw an exception.
        valueToFind = 4;
        std::deque<int>::iterator dequeResult = easyfind(myDeque, valueToFind);
        if (dequeResult != myDeque.end())
            std::cout << "Value " << valueToFind << " found in deque at position " << std::distance(myDeque.begin(), dequeResult) << std::endl;
        else
            std::cout << "Value " << valueToFind << " not found in deque." << std::endl;
    }
    catch (const NotFound& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
