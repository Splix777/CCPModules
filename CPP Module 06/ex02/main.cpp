#include "Base.hpp"  // Include the header files for your classes
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Function to generate an instance of A, B, or C randomly
static Base* generate(void)
{
    // Use rand() % 3 to get a random number between 0 and 2
    switch (rand() % 3)
    {
        case 0:
            return (new A()); // Create and return an instance of class A
            break ;
        case 1:
            return (new B()); // Create and return an instance of class B
            break ;
        case 2:
            return (new C()); // Create and return an instance of class C
            break ;
        default:
            perror("Error creating a random class.");
            return (NULL); // Return NULL in case of an error
    }
}

/* dynamic_cast Overview:

   How dynamic_cast Works:
   - Requires a polymorphic base class with at least one virtual function.
   - Attempts to perform a type cast, checking if the object is of the target type or derived type.
   - If types are compatible, a successful cast returns a pointer/reference to the derived type.
   - If the object is null, the result of the cast is also null.
   - If the cast is invalid, dynamic_cast returns null (pointer) or throws std::bad_cast (reference).

   Uses of dynamic_cast:
   - Runtime Type Identification (RTTI): Identify derived type of a polymorphic object.
   - Safeguarding Downcasting: Ensures validity before downcasting a base pointer/reference.
   - Type-Safe Object Manipulation: Prevents invalid memory access due to incorrect casting.
   - Hierarchical Operations: Implement behavior based on actual object types in complex hierarchies.
   - Factory Design Patterns: Check and manipulate objects of different derived classes.

   Variables It Takes:
   - Requires a base class pointer/reference to cast (basePointer or baseReference).
   - Specify desired derived type in angle brackets (dynamic_cast<DerivedType*>
   or dynamic_cast<DerivedType&>).

   Limitations:
   - Works with pointers and references, not object values.
   - Slower than static_cast due to runtime type checks.
   - Available only for polymorphic classes (with at least one virtual function).
   - Does not work across unrelated class hierarchies.

   Summary:
   dynamic_cast is crucial for working with polymorphic objects. It ensures safe and
   type-correct casting in scenarios involving base and derived class pointers/references.
   Determine actual object types at runtime for dynamic and type-safe behaviors.
*/


// Function to identify the type using Base pointer
static void identify(Base* p)
{
    // Use dynamic_cast to check if p can be cast to type A
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl; // Print if p is of type A
    // Use dynamic_cast to check if p can be cast to type B
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl; // Print if p is of type B
    // Use dynamic_cast to check if p can be cast to type C
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl; // Print if p is of type C
    else
        std::cout << "Unknown" << std::endl; // Print if p's type is unknown
}

// Function to identify the type using Base reference
static void identify(Base& p)
{
	try
	{
		A ptr;

		ptr = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
    catch (const std::exception& e)
    {}
	try
	{
		B ptr;

		ptr = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
    catch (const std::exception& e)
    {}
	try
	{
		C ptr;

		ptr = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
    catch (const std::exception& e)
    {}
}

int main()
{
    // Loop to generate and test instances 4 of A, B, and C
    for (int j = 0; j < 5; j++)
    {
        Base* Test = generate(); // Generate a random instance of A, B, or C
        if (Test == NULL)
            return (1);
        else
        {
            std::cout << "Instance " << j + 1 << ": " << std::endl; // Print the instance number
            std::cout << "Identifying using pointer: ";
            identify(Test);     // Identify type using Base pointer
            std::cout << "Identifying using reference: ";
            identify(*Test);    // Identify type using Base reference
            delete (Test);      // Clean up memory by deleting the instance

            std::cout << std::endl; // Print an empty line for separation
        }
    }
    return (0); // Return 0 to indicate successful execution
}

/*  Concept Explanation:

    The concept behind this exercise revolves around polymorphism, dynamic
    casting, and the identification of object types at runtime.

    Polymorphism:
    In object-oriented programming, polymorphism allows objects of
    different classes to be treated as objects of a common base class.
    This abstraction enables you to write code that operates on the base
    class and works seamlessly with objects of any derived class,
    without knowing their specific types. Polymorphism provides
    flexibility, modularity, and abstraction.

    Dynamic Casting:
    C++ provides "dynamic_cast," a mechanism that enables safe conversion
    of pointers or references from a base class to pointers or references
    of derived classes at runtime. It's particularly useful for determining
    whether a cast from a base class to a derived class is valid during runtime.
    This is essential when working with polymorphic objects, as the specific
    type of an object might not be known at compile-time.

    Purpose of the Exercise:

    The purpose of this exercise is multi-fold:

    1. Polymorphic Behavior:
       By creating derived classes (A, B, C) that inherit from a shared base
       class (Base), you practice polymorphism. This means you can treat objects
       of these derived classes as if they were objects of the base class.
       This approach facilitates unified interactions with these objects.

    2. Dynamic Casting:
       The exercise highlights dynamic casting's significance in determining
       the actual derived class type an object belongs to at runtime.
       Dynamic_cast provides information about whether a cast from a base
       class pointer/reference to a derived class is successful.
       This runtime knowledge is crucial for making informed decisions
       about object handling.

    3. Type Identification:
       The `identify` functions showcase your ability to identify an
       object's actual type at runtime. This skill is invaluable for debugging,
       logging, and dynamic decision-making based on object types.

    4. Random Object Generation:
       The `generate` function simulates random object creation of different 
        derived classes. This demonstrates how polymorphism allows writing generic
        code that accommodates various derived classes without prior knowledge
        of their specifics.

    5. Testing Polymorphism:
       The exercise's primary objective is to test your grasp of polymorphic
       behavior, dynamic casting, and runtime type identification. These skills
       are pivotal when working with complex class hierarchies and object-oriented
       designs. The exercise solidifies your understanding of how C++ supports
       polymorphism and its application to write flexible and maintainable code.

    Overall, this exercise reinforces your understanding of polymorphism, 
    dynamic_cast, and runtime type identification – skills critical for
    handling intricate software systems. It exemplifies C++'s support for
    polymorphism and demonstrates how it enhances code flexibility and maintainability.*/
