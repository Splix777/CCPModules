#include "Serialization.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

// Function: serialize
// Converts a pointer to a `Data` object into an unsigned integer value (uintptr_t).
// This function simulates serialization by converting the memory address of the object into
// an integer, allowing for storage, transmission, or representation in an integer-based format.
// The `ptr` parameter is a pointer to the original `Data` object.
// Returns: An unsigned integer (uintptr_t) representation of the memory address of the `ptr`.
uintptr_t Serializer::serialize(Data* ptr)
{
    // Use reinterpret_cast to convert the pointer `ptr` to an unsigned integer value
    // (uintptr_t) without any changes to the memory content.
    return (reinterpret_cast<uintptr_t>(ptr));
}

// Function: deserialize
// Converts an unsigned integer value (uintptr_t) back into a pointer to a `Data` object.
// This function simulates deserialization by converting the integer value (representing
// a memory address) back into a valid pointer to the original `Data` object.
// The `raw` parameter is the unsigned integer value that was obtained from the serialization process.
// Returns: A pointer to the original `Data` object corresponding to the given `raw` value.
Data* Serializer::deserialize(uintptr_t raw)
{
    // Use reinterpret_cast to convert the unsigned integer value (uintptr_t) `raw` back into
    // a pointer to the original `Data` object. This reconstructs the memory address from the integer value.
    return (reinterpret_cast<Data*>(raw));
}
