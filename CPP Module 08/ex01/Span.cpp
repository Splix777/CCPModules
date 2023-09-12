/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:05:03 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:05:03 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default Constructor: Initializes size and pos to 0
Span::Span() : size(0)
{
    std::cout << "Default Span constructor called." << std::endl;
}

// Parameterized constructor: Takes an integer N as input and sets size and pos
Span::Span(unsigned int N) : size(N)
{
    std::cout << "Span Constructor called with a max size of: " << N << std::endl;
}

// Destructor: Called when an object of the class is destroyed
Span::~Span()
{
    std::cout << "Span Deconstructor called." << std::endl;
}

// Copy constructor: Creates a new object by copying values from an existing object
Span::Span(Span const &copy)
{
    this->size = copy.size; // Copy the size from the source object
    std::cout << "Span Copy Constructor called." << std::endl; // Print message
}

// Assignment operator overload: Copies values from another object to the current object
Span    &Span::operator=(Span const &copy)
{
    if (this != &copy) // Check for self-assignment
    {
        this->size = copy.size; // Copy the size from the source object
    }
    std::cout << "Span operator overload called." << std::endl;
    return (*this); // Return the reference to the current object
}

// Adds a number to the vector
void    Span::addNumber(int number)
{
    if (this->vector.size() == this->size) // Check if the vector is full
        throw Span::ContainerFull(); // Throw an exception if the vector is full
    vector.push_back(number); // Add the number to the vector
}

// Fills the vector with random values
void Span::fill()
{
    if (vector.size() >= size) // Check if the vector is already full
        return ; // If so, exit the function

    while (vector.size() < size) // Loop until the vector is filled
    {
        int randomValue = (rand() % size) + 1; // Generate a random value
        vector.push_back(randomValue); // Add the random value to the vector
    }
}

// Returns the shortest span between adjacent numbers in the vector
unsigned int Span::shortestSpan() const
{
    if (vector.size() < 1) // Check if the vector is empty
        throw Span::ContainerEmpty(); // Throw an exception if the vector is empty
    if (vector.size() < 2) // Check if the vector has only one element
        throw Span::ContainerOnlyOne(); // Throw an exception if the vector has only one element

    std::vector<int> sortedVector = vector; // Create a copy of the vector
    std::sort(sortedVector.begin(), sortedVector.end()); // Sort the copy

    unsigned int minSpan = std::numeric_limits<unsigned int>::max(); // Initialize minSpan
    for (size_t i = 1; i < sortedVector.size(); ++i) // Loop through the sorted vector
    {
        unsigned int span = static_cast<unsigned int>(sortedVector[i]) - static_cast<unsigned int>(sortedVector[i - 1]); // Calculate span
        if (span < minSpan) // Compare with current minSpan
            minSpan = span; // Update minSpan if necessary
    }
    return (minSpan); // Return the minimum span    
}

// Returns the longest span between the maximum and minimum values in the vector
unsigned int Span::longestSpan() const
{
    if (vector.size() < 1) // Check if the vector is empty
        throw Span::ContainerEmpty(); // Throw an exception if the vector is empty
    if (vector.size() < 2) // Check if the vector has only one element
        throw Span::ContainerOnlyOne(); // Throw an exception if the vector has only one element

    int minVal = vector[0]; // Initialize minVal with the first element
    int maxVal = vector[0]; // Initialize maxVal with the first element

    for (size_t i = 1; i < vector.size(); ++i) // Loop through the vector
    {
        if (vector[i] < minVal) // Compare with current minVal
            minVal = vector[i]; // Update minVal if necessary
        if (vector[i] > maxVal) // Compare with current maxVal
            maxVal = vector[i]; // Update maxVal if necessary
    }

    return (static_cast<unsigned int>(maxVal) - static_cast<unsigned int>(minVal)); // Return the difference
}

unsigned int    Span::getSize() const // Return the size of the vector
{
    return (this->size);
}
