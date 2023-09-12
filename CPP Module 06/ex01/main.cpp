/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:02:41 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:02:42 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"  // Include the header file that defines Serializer and Data

int main()
{
    Serializer serializer;  // Create an instance of the Serializer class

    Data data;  // Create a Data object named 'data'
    data.value = 42;        // Assign an integer value to the 'value' member of the Data object
    data.character = 'A';   // Assign a character value to the 'character' member of the Data object

    // Serialize the memory address of the 'data' object using the 'serialize' method
    uintptr_t serialized = serializer.serialize(&data);

    // Deserialize the serialized value back to a Data pointer using the 'deserialize' method
    Data* deserialized = serializer.deserialize(serialized);

    // Check if the deserialized pointer is equal to the address of the original 'data' object
    if (deserialized == &data)
        std::cout << "Serialization and deserialization worked correctly!\n";
    else
        std::cout << "Serialization and deserialization failed.\n";
    return (0);
}

/*
Explanation of Serialization and Deserialization:

Serialization and deserialization are concepts used in computer science 
to transform data into a format that can be easily stored, transmitted, or
reconstructed. Serialization involves converting complex data structures,
like objects or structs, into a simpler format (such as integers or bytes)
that can be saved or transmitted efficiently. Deserialization is the reverse
process, where the serialized data is reconstructed back into its original format.

In the context of the provided code:

- The Data struct is a simple data structure containing an integer and a character,
simulating some meaningful data.

- The Serializer class contains methods for converting between the original
data and a serialized format.

- In the main function, an instance of the Serializer class is created, and a
Data object named data is initialized with values.

- The serialize method of the Serializer instance is used to convert the memory
address of the data object into an unsigned integer (uintptr_t) value.

- The deserialize method of the Serializer instance is used to convert the
serialized integer back into a pointer, which should point to the original data object.

- The program then compares the deserialized pointer with the address of the
original data object. If they are the same, it means that the serialization
and deserialization process worked correctly, indicating that the original
data has been successfully reconstructed from the serialized form.

- The program's output will indicate whether the serialization and
deserialization were successful or not.

Serialization and deserialization are fundamental concepts in various domains
of computer science, including data storage, network communication, and more.
They allow for efficient data exchange and persistence in various scenarios.
*/