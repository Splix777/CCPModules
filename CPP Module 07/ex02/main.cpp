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
            arr2[10]; // This should throw an exception
        }
        catch (const std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        // Test explicit use of constructor
        // Array<int> arr5 = 10; // Uncommenting this should cause a compilation error
    } 
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        // Test new int() and display value
        int* a = new int();
        std::cout << "*a: " << *a << std::endl;
        delete a;

        // Test default constructor
        Array<int> arr1;
        std::cout << "arr1 size: " << arr1.size() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
