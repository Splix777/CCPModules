#pragma once

// Include necessary headers
#include <iostream>   // For standard input/output
#include <string.h>   // For C-style string functions
#include <stdint.h>   // For uintptr_t definition

// Define a simple struct named Data to hold data members
typedef struct Data
{
    int value;        // An integer value
    char character;   // A character value
} Data;

// Define a class named Serializer
class Serializer
{
public:
    // Function: serialize
    // Converts a pointer to a Data object into an unsigned integer value (uintptr_t).
    // This function simulates serialization by converting the memory address of the object into
    // an integer, allowing for storage, transmission, or representation in an integer-based format.
    // The ptr parameter is a pointer to the original Data object.
    // Returns: An unsigned integer (uintptr_t) representation of the memory address of the ptr.
    static uintptr_t serialize(Data* ptr);

    // Function: deserialize
    // Converts an unsigned integer value (uintptr_t) back into a pointer to a Data object.
    // This function simulates deserialization by converting the integer value (representing
    // a memory address) back into a valid pointer to the original Data object.
    // The raw parameter is the unsigned integer value that was obtained from the serialization process.
    // Returns: A pointer to the original Data object corresponding to the given raw value.
    static Data* deserialize(uintptr_t raw);
};
