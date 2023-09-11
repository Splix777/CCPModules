#include "PmergeMe.hpp"
// Default constructor
PmergeMe::PmergeMe() {}
// Copy constructor
PmergeMe::PmergeMe(PmergeMe const &copy) : size(copy.size), _vectorSortingTime(copy._vectorSortingTime), _dequeSortingTime(copy._dequeSortingTime) {}
// Destructor
PmergeMe::~PmergeMe() {}
// Assignment operator overload
PmergeMe &PmergeMe::operator=(PmergeMe const &copy)
{
    if (this != &copy)
    {
        size = copy.size;
        _vectorSortingTime = copy._vectorSortingTime;
        _dequeSortingTime = copy._dequeSortingTime;
    }
    return (*this);
}
// Constructor with arguments
PmergeMe::PmergeMe(int argc, char **argv)
{
    // Check if there are any arguments
    if (argc < 2)
        throw std::invalid_argument("No arguments provided: ./PmergeMe [arg1] [arg2] [...]");
    size = argc - 1;
    parseArgs(argc, argv);
}
// Parse the arguments
void PmergeMe::parseArgs(int argc, char **argv)
{
    // Iterate through the arguments
    for (int i = 1; i < argc; i++)
    {
        // Stringstream to parse the argument
        std::stringstream ss(argv[i]);
        // Temporary string to store the argument
        std::string temp;
        // Temporary int to store the argument
        int num;

        // Parse the argument
        ss >> temp;
        // Check if the argument is a number
        if (temp.find_first_not_of("0123456789") != std::string::npos)
            throw std::invalid_argument("Invalid argument: " + temp);
        // Convert the argument to an int
        num = std::atoi(temp.c_str());
        // Add the int to the unsorted container
        _unsorted.push_back(num);
    }
}
// Template function to sort a container. We use a template function so that we can use the same function for both std::vector and std::deque.
/*
    *   std::upper_bound is a standard library function that performs a binary
        search in a sorted range (in this case, the _vector container) to find
        the position where a specified element (*it) should be inserted while
        maintaining the sorted order.
    *   _vector.begin() and _vector.end() define the range within which the
        binary search is performed, which is the entire _vector container.
    *   The result of std::upper_bound is an iterator pointing to the position
        where the element should be inserted.
    *   We use std::vector::insert to insert the element at the found position.
    *   Since _vector is a std::vector, it supports efficient insertion at
        specific positions due to its underlying dynamic array structure.
        The insert function inserts the element at the specified position and
        shifts the subsequent elements, if necessary, to make room for the
        new element while maintaining the sorted order.
    *   This is why you see the sorting time for std::vector is much faster
        than that of std::deque.
*/
template <typename Container>
void PmergeMe::mergeVectorSort(Container &container)
{
    // Iterate through the container. Since we are using a template function, we need to use typename to tell the compiler that Container::iterator is a type.
    for (typename Container::iterator it = container.begin(); it != container.end(); ++it)
    {
        // Find the insertion point in the sorted portion of the vector
        typename std::vector<int>::iterator insertionPoint = std::upper_bound(_vector.begin(), _vector.end(), *it);

        // Insert the element at the found position
        _vector.insert(insertionPoint, *it);
    }
}
// Template function to sort a container. We use a template function so that we can use the same function for both std::vector and std::deque.
/*
    *   std::upper_bound is a standard library function that performs a binary
        search in a sorted range (in this case, the _deque container) to find
        the position where a specified element (*it) should be inserted while
        maintaining the sorted order.
    *   _deque.begin() and _deque.end() define the range within which the
        binary search is performed, which is the entire _deque container.
    *   The result of std::upper_bound is an iterator pointing to the position
        where the element should be inserted.
    *   We use std::deque::insert to insert the element at the found position.
    *   Since _deque is a std::deque, it does not support efficient insertion
        at specific positions due to its underlying doubly-linked list structure.
        The insert function inserts the element at the specified position and
        shifts the subsequent elements, if necessary, to make room for the
        new element while maintaining the sorted order.
    *   This is why you see the sorting time for std::deque is much slower
        than that of std::vector.
*/
template <typename Container>
void PmergeMe::mergeDequeSort(Container &container)
{
    for (typename Container::iterator it = container.begin(); it != container.end(); ++it)
    {
        // Find the insertion point in the sorted portion of the vector
        typename std::deque<int>::iterator insertionPoint = std::upper_bound(_deque.begin(), _deque.end(), *it);

        // Insert the element at the found position
        _deque.insert(insertionPoint, *it);
    }
}
// Template function to measure the sorting time for a container. We use a template function so that we can use the same function for both std::vector and std::deque.
/*
    *   clock_t is a type that stores the number of clock ticks.
    *   clock() is a standard library function that returns the number of
        clock ticks since the program started.
    *   CLOCKS_PER_SEC is a standard library macro that defines the number of
        clock ticks per second.
    *   We use clock() to get the number of clock ticks before and after the
        sorting operation and then calculate the elapsed time.
    *   We multiply the elapsed time by 1000000.0 to convert it to microseconds.
*/
template <typename Container>
void PmergeMe::measureSortingTime(Container &container)
{
    // Start the clock
    clock_t start = clock();
    // Call mergeVectorSort to perform the sorting
    mergeVectorSort(container);
    // Stop the clock
    clock_t end = clock();
    // Calculate the elapsed time
    double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0; // Convert to microseconds
    // Store the elapsed time
    _vectorSortingTime = elapsedTime;

    // Start the clock
    start = clock();
    // Call mergeVectorSort to perform the sorting
    mergeDequeSort(container);
    // Stop the clock
    end = clock();
    // Calculate the elapsed time
    elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0; // Convert to microseconds
    // Store the elapsed time
    _dequeSortingTime = elapsedTime;
}
// Run the sorting and display the sorted container along with sorting time
void PmergeMe::run()
{
    // Perform sorting and measure time
    measureSortingTime(_unsorted);
    // Display the before and after containers
    displayContainers();
    // Display the sorting time for each type of container
    std::cout << "Time to process a range of " << size << " elements with std::vector : " << _vectorSortingTime << " us" << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::deque : " << _dequeSortingTime << " us" << std::endl;
}
// Display the before and after containers
void PmergeMe::displayContainers()
{
    int i;

    std::cout << "Before:";
    // Print unsorted container if it has less than 5 elements
    if (_unsorted.size() <= 5)
    {
        for (typename std::deque<int>::iterator it = _unsorted.begin(); it != _unsorted.end(); ++it)
        {
            std::cout << " " << *it;
        }
    }
    // Print the first 5 elements of the unsorted container and then print [...]
    else
    {
        typename std::deque<int>::iterator it = _unsorted.begin();
        for (i = 0; i < 5; i++)
        {
            std::cout << " " << *it;
            ++it;
        }
        std::cout << " [...]";
    }
    std::cout << std::endl;

    std::cout << "After:";
    // Print sorted container if it has less than 5 elements
    if (_vector.size() <= 5)
    {
        for (typename std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
        {
            std::cout << " " << *it;
        }
    }
    // Print the first 5 elements of the sorted container and then print [...]
    else
    {
        typename std::vector<int>::iterator it = _vector.begin();
        for (i = 0; i < 5; i++)
        {
            std::cout << " " << *it;
            ++it;
        }
        std::cout << " [...]";
    }
    std::cout << std::endl;
}

