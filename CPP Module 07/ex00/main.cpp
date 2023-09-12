/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:04:04 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:04:04 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
    int a = 2;
    int b = 3;

    ::swap( a, b );

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);

    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    char e = 'x';
    char f = 'z';

    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

    double g = 1.5;
    double h = 2.7;

    ::swap(g, h);
    std::cout << "g = " << g << ", h = " << h << std::endl;
    std::cout << "min(g, h) = " << ::min(g, h) << std::endl;
    std::cout << "max(g, h) = " << ::max(g, h) << std::endl;

    int i = 2;
    int j = 2;

    ::swap(i, j);
    std::cout << "i = " << i << ", j = " << j << std::endl;
    std::cout << "min(i, j) = " << ::min(i, j) << std::endl;
    std::cout << "max(i, j) = " << ::max(i, j) << std::endl;

    return (0);
}

/*
1. Uses of Templates:
Templates allow you to create generic code that can work with
different types. They are used to achieve the following goals:

- Code Reusability: You can write a single template implementation
that works for multiple types, eliminating the need to duplicate
code for each type.

- Generic Algorithms and Data Structures: Templates are the
foundation of the C++ Standard Template Library (STL), providing
generic algorithms (like sorting and searching) and data structures
(like vectors, lists, and maps).

- Type-Independent Functions and Classes: Templates enable you to
define functions and classes that operate independently of the data
types they work with.

2. Syntax and Format:

Function Templates:

template <typename T>
returnType functionName(parameters) {
    // Template function body
}

Class Templates:

template <typename T>
class ClassName {
    // Template class body
};

- Type Deduction: The typename keyword or the class keyword is used
to introduce the type parameter T. This parameter is a placeholder
for the actual type that will be provided when the template is used.

3. Examples:

Function Template Example:

template <typename T>
T add(T a, T b) {
    return a + b;
}

Class Template Example:

template <typename T>
class MyContainer {
    T data;
public:
    MyContainer(T value) : data(value) {}
    T getValue() { return data; }
};

Using Templates:

int sum = add(5, 3);  // T is deduced as int
MyContainer<int> container(42);  // Instantiate MyContainer with int type


4. Template Specialization:
In some cases, you might want to provide a specialized version of a
template for a specific type. This is called template specialization.

template<>
class MyContainer<char> {
    char data;
public:
    MyContainer(char value) : data(value) {}
    char getValue() { return data; }
};


5. Template Constraints:
In C++11 and later versions, you can use type traits and concepts to
constrain templates to work only with types that fulfill specific requirements.

6. Variadic Templates:
Variadic templates allow you to define functions or classes that take a
variable number of arguments of different types.

7. Example with the Standard Library:
The C++ Standard Library extensively uses templates. For instance, std::vector,
std::list, and std::map are implemented as template classes.

Templates are a cornerstone of modern C++ programming, enabling the creation
of flexible, generic, and efficient code. They provide the foundation for
a wide range of libraries, frameworks, and applications.
*/