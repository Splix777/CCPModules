/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:04:27 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/26 14:40:53 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

// Constructor for Array class with no parameters
template <typename T>
Array<T>::Array() : data(new T[0]), arraySize(0)
{
    if (data == NULL)
        throw std::bad_alloc();
    // Print a message indicating that the default constructor has been called
    std::cout << "Default constructor called. Array initialized to a size of 0" << std::endl;
}

// Constructor for Array class with an unsigned int parameter
template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), arraySize(n)
{
    if (data == NULL)
        throw std::bad_alloc();
    // Initialize each element in the array to its default value
    for (unsigned int i = 0; i < n; ++i)
    {
        data[i] = T(); // Default initialization
    }
    // Print a message indicating the constructor has been called and the size of the array
    std::cout << "Constructor called. Array initialized to an array size of " << n << std::endl;
}

// Destructor for the Array class
template <typename T>
Array<T>::~Array()
{
    // Delete the dynamically allocated array to prevent memory leaks
    if (this->data != NULL)
        delete[] data;
}

// Copy constructor for the Array class
template <typename T>
Array<T>::Array(const Array &other) : data(new T[other.arraySize]), arraySize(other.arraySize)
{
    if (data == NULL)
        throw std::bad_alloc();
    // Copy each element from the source array to the new array
    for (unsigned int i = 0; i < arraySize; ++i)
    {
        data[i] = other.data[i];
    }
    // Print a message indicating the copy constructor has been called
    std::cout << "Copy Constructor called" << std::endl;
}

// Copy assignment operator for the Array class
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    // Check for self-assignment
    if (this != &other)
    {
        // Delete the existing array
        delete[] data;
        // Copy the size from the other array
        arraySize = other.arraySize;
        // Allocate memory for the new array and copy its elements
        data = new T[arraySize];
        if (data == NULL)
            throw std::bad_alloc();
        for (unsigned int i = 0; i < arraySize; ++i) {
            data[i] = other.data[i];
        }
    }
    // Print a message indicating the copy assignment operator has been called
    std::cout << "Operator overload called" << std::endl;
    return (*this);
}

// Subscript operator for accessing array elements
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    // Check if the index is within bounds
    if (index >= arraySize)
    {
        // Throw an exception if the index is out of bounds
        throw InvalidIndexException();
    }
    // Return a reference to the requested array element
    return (data[index]);
}

// Const subscript operator for accessing array elements (for const instances)
template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    // Check if the index is within bounds
    if (index >= arraySize)
    {
        // Throw an exception if the index is out of bounds
        throw InvalidIndexException();
    }
    // Return a const reference to the requested array element
    return (data[index]);
}

// Member function to get the size of the array
template <typename T>
unsigned int Array<T>::size() const
{
    // Return the size of the array
    return (this->arraySize);
}

// Implementation of the InvalidIndexException class
template< typename T >
const char *Array<T>::InvalidIndexException::what() const throw()
{
    // Return an error message indicating an invalid index
    return ("Error: Invalid index");
}

#endif // ARRAY_TPP
