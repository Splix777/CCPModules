/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:04:30 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/26 14:41:54 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    try
    {
        // Test default constructor
        Array<int> arr1;
        std::cout << "arr1 size: " << arr1.size() << std::endl;

        // Test explicit constructor
        Array<int> arr2(5);
        std::cout << "arr2 size: " << arr2.size() << std::endl;

        // Test subscript operator and size
        for (unsigned int i = 0; i < arr2.size(); ++i)
        {
            arr2[i] = i * 10;
        }

        // Test copy constructor and assignment operator
        Array<int> arr3 = arr2;
        std::cout << "Copy constructor called for arr3 at address: " << &arr3 << std::endl;
        Array<int> arr4;
        arr4 = arr2;
        std::cout << "Copy assignment operator called for arr4 at address: " << &arr4 << std::endl;

        // Test const subscript operator and size
        const Array<int>& constArr = arr2;
        for (unsigned int i = 0; i < constArr.size(); ++i)
        {
            std::cout << constArr[i] << " ";
        }
        std::cout << std::endl;

        // Test out-of-bounds exception
        try
        {
            arr2[5]; // This should throw an exception
        }
        catch (const std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        // Test explicit use of constructor
        // Uncommenting this should cause a compilation error
        // Array<int> arr5 = 10;
    } 
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "-----INT ARRAY------" << std::endl;
    try
    {
        // Test new int() and display value
        int * a = new int();
        std::cout << "*a: " << *a << std::endl;
        delete a;

        // Test default constructor
        Array<int> arr1;
        std::cout << "arr1 size: " << arr1.size() << std::endl;
        arr1 = Array<int>(5);
        arr1[0] = 1;
        arr1[1] = 2;
        arr1[2] = 3;
        arr1[3] = 4;
        arr1[4] = 5;
        // Remove comment to test out-of-bounds exception
        // arr1[5] = 6;
        std::cout << "arr1 size: " << arr1.size() << std::endl;
        for (unsigned int i = 0; i < arr1.size(); ++i)
        {
            std::cout << arr1[i] << " ";
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "-----CHAR ARRAY------" << std::endl;
    try
    {
        Array<char> arr1(5);
        std::cout << "arr1 size: " << arr1.size() << std::endl;
        arr1[0] = 'a';
        arr1[1] = 'b';
        arr1[2] = 'c';
        arr1[3] = 'd';
        arr1[4] = 45;
        // Remove comment to test out-of-bounds exception
        // arr1[5] = 'f';

        for(unsigned int i = 0; i < arr1.size(); i++)
            std::cout << arr1[i] << " ";
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "-----FLOAT ARRAY------" << std::endl;
    try
    {
        Array<float> arr1(5);
        std::cout << "arr1 size: " << arr1.size() << std::endl;
        arr1[0] = 1.1f;
        arr1[1] = 2.2f;
        arr1[2] = 3.3f;
        arr1[3] = 4.4f;
        arr1[4] = 5.5f;
        // Remove comment to test out-of-bounds exception
        // arr1[5] = 6.6f;

        for(unsigned int i = 0; i < arr1.size(); i++)
            std::cout << arr1[i] << " ";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
    return (0);
}

// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }