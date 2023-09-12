/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:04:24 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:04:24 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <stdexcept>
# include <cstdlib>
# include <ctime>


template <typename T>
class Array
{
    private:
        T *data;
        unsigned int arraySize;
    
    public:
        // Constructor
        Array();
        explicit Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);        
        // Deconstructor
        ~Array();
        // Subscript operator
        T   &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;
        // Member function
        unsigned int size() const;
        // Exception
        class InvalidIndexException : public std::exception
        {
            public:
                virtual const char  *what() const throw();
        };
};

#include "Array.tpp"

#endif

/*
The explicit keyword in C++ serves as a modifier for constructors.
When applied to a constructor, it prevents the compiler from
automatically performing implicit type conversions in certain
situations. Let's explore this in more detail and understand
how it's used in the context of your Array class.

1. Implicit Type Conversion:
In C++, constructors can be used for implicit type conversions.
For example, if you have a constructor that takes a single argument
of a different type, the compiler might automatically use that
constructor to convert the argument to the class type. This behavior
can lead to unexpected or unintended conversions.

Here's an example:

class MyClass {
public:
    MyClass(int value) { ... }
};

int main() {
    MyClass obj = 42;  // Implicit conversion
    return 0;
}

In this example, an integer 42 is implicitly converted to a MyClass
object using the constructor MyClass(int value). This kind of
conversion can sometimes lead to confusion or unexpected behavior.

2. The explicit Keyword:
The explicit keyword is used to prevent such implicit conversions
by marking constructors as "non-implicit." When a constructor
is marked as explicit, the compiler will not automatically
use it for type conversions. Instead, you need to explicitly
invoke the constructor to create an object.

In relation to the Array Class:
    explicit Array(unsigned int size);

In Array class, the constructor with the explicit keyword
prevents the compiler from using this constructor for implicit
conversions. For instance, without the explicit keyword, the
following might work:

Array<int> arr = 5;  // Implicit conversion: size constructor with 5 elements

The explicit keyword ensures that this doesn't happen and you need
to explicitly call the constructor:

Array<int> arr(5);  // Explicit constructor call with size 5

By using explicit in this context, you're making it clear that
creating an Array instance with an explicit size is a deliberate
choice, preventing any unintentional or ambiguous conversions.

In summary, the explicit keyword in C++ is used to prevent
automatic type conversions that might lead to unexpected behavior.
It's a way to make the code more clear and less prone to errors
by requiring explicit constructor calls. In your Array class,
marking the constructor with explicit ensures that you have to
be explicit when creating an array with a specific size, rather
than relying on implicit conversions.
*/