/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:06:10 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/28 12:32:27 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
// Default constructor
PmergeMe::PmergeMe() {}
// Copy constructor
PmergeMe::PmergeMe(PmergeMe const &copy)
{
    _vector = copy._vector;
    _deque = copy._deque;
    _unsorted = copy._unsorted;
    size = copy.size;
    _vectorSortingTime = copy._vectorSortingTime;
    _dequeSortingTime = copy._dequeSortingTime;
}
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
        _vector = copy._vector;
        _deque = copy._deque;
        _unsorted = copy._unsorted;
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
        _vector.push_back(num);
        _deque.push_back(num);
        _unsorted.push_back(num);
    }
}

void PmergeMe::mergeVector(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftSubvec(n1);
    std::vector<int> rightSubvec(n2);

    for (int i = 0; i < n1; i++)
        leftSubvec[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightSubvec[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftSubvec[i] <= rightSubvec[j]) {
            arr[k] = leftSubvec[i];
            i++;
        } else {
            arr[k] = rightSubvec[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftSubvec[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightSubvec[j];
        j++;
        k++;
    }
}

void PmergeMe::insertionSortVector(std::vector<int> &arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }    
}

void PmergeMe::mergeInsertVectorSort(std::vector<int> &arr, int left, int right)
{
    if  (left < right)
    {
        if (right - left + 1 <= calculateThreshold(right - left + 1))
        {
            insertionSortVector(arr, left, right);
        }
        else
        {
            int mid = left + (right - left) / 2;
            mergeInsertVectorSort(arr, left, mid);
            mergeInsertVectorSort(arr, mid + 1, right);
            mergeVector(arr, left, mid, right);
        }
    }
}

void PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::deque<int> leftSubvec(n1);
    std::deque<int> rightSubvec(n2);

    for (int i = 0; i < n1; i++)
        leftSubvec[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightSubvec[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftSubvec[i] <= rightSubvec[j]) {
            arr[k] = leftSubvec[i];
            i++;
        } else {
            arr[k] = rightSubvec[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftSubvec[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightSubvec[j];
        j++;
        k++;
    }
}

void PmergeMe::insertionSortDeque(std::deque<int> &arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }    
}

void PmergeMe::mergeInsertDequeSort(std::deque<int> &arr, int left, int right)
{
    if  (left < right)
    {
        if (right - left + 1 <= calculateThreshold(right - left + 1))
        {
            insertionSortDeque(arr, left, right);
        }
        else
        {
            int mid = left + (right - left) / 2;
            mergeInsertDequeSort(arr, left, mid);
            mergeInsertDequeSort(arr, mid + 1, right);
            mergeDeque(arr, left, mid, right);
        }
    }
}

void PmergeMe::measureSortingTime()
{
    // Start the clock
    clock_t vstart = clock();
    // Call mergeVectorSort to perform the sorting
    mergeInsertVectorSort(_vector, 0, _vector.size() - 1);
    // Stop the clock
    clock_t vend = clock();
    // Calculate the elapsed time
    double elapsedTime = static_cast<double>(vend - vstart) / CLOCKS_PER_SEC * 1000000.0; // Convert to microseconds
    // Store the elapsed time
    _vectorSortingTime = elapsedTime;

    // Start the clock
    clock_t dstart = clock();
    // Call mergeVectorSort to perform the sorting
    mergeInsertDequeSort(_deque, 0, _deque.size() - 1);
    // Stop the clock
    clock_t dend = clock();
    // Calculate the elapsed time
    elapsedTime = static_cast<double>(dend - dstart) / CLOCKS_PER_SEC * 1000000.0; // Convert to microseconds
    // Store the elapsed time
    _dequeSortingTime = elapsedTime;
}

void PmergeMe::run()
{
    // Perform sorting and measure time
    measureSortingTime();
    if (!isSortedDeque(_deque) || !isSortedVector(_vector))
        std::cout << "Failed to sort the arrays!" << std::endl;
    // Display the before and after containers
    displayContainers();
    // Display the sorting time for each type of container
    std::cout << "Time to process a range of " << size << " elements with std::vector : " << _vectorSortingTime << " us" << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::deque : " << _dequeSortingTime << " us" << std::endl;
}

void PmergeMe::displayContainers()
{
    int i;

    std::cout << "Before:";
    // Print unsorted container if it has less than 5 elements
    if (_unsorted.size() <= 5)
    {
        for ( std::deque<int>::iterator it = _unsorted.begin(); it != _unsorted.end(); ++it)
        {
            std::cout << " " << *it;
        }
    }
    // Print the first 5 elements of the unsorted container and then print [...]
    else
    {
        std::deque<int>::iterator it = _unsorted.begin();
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
        for ( std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
        {
            std::cout << " " << *it;
        }
    }
    // Print the first 5 elements of the sorted container and then print [...]
    else
    {
         std::vector<int>::iterator it = _vector.begin();
        for (i = 0; i < 5; i++)
        {
            std::cout << " " << *it;
            ++it;
        }
        std::cout << " [...]";
    }
    std::cout << std::endl;
    
}

int PmergeMe::calculateThreshold(int threshold)
{
    return (std::max(10, threshold / 10));
}

bool PmergeMe::isSortedVector(std::vector<int> &arr)
{
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        if (it > (it + 1))
        {
            std::cout << "Not sorted" << std::endl;
            return (false);
        }
    }
    return (true);
}

bool PmergeMe::isSortedDeque(std::deque<int> &arr)
{
    for (std::deque<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        if (it > (it + 1))
        {
            std::cout << "Not sorted" << std::endl;
            return (false);
        }
    }
    return (true);
}