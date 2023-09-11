#include "iter.hpp"
// Prints Square of a number
static void printSquare(int num)
{
    std::cout << num * num << " ";
}
// Prints Double of a number
static void printDouble(double num)
{
    std::cout << num * 2 << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    iter(intArray, 5, printSquare);
    std::cout << std::endl;
    
    iter(doubleArray, 5, printDouble);
    std::cout << std::endl;

    return 0;
}