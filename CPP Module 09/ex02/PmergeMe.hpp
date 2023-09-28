/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:06:13 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/28 12:36:28 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>    // Input and output stream operations, used for console input/output.
# include <vector>      // Container class for dynamic arrays, used to store data.
# include <deque>       // Container class for double-ended queues, another data storage option.
# include <sstream>     // String stream classes, used for parsing command-line arguments.
# include <ctime>       // C library functions for time and clock operations, used for measuring execution time.
# include <cstdlib>     // General purpose C library functions, used for string to integer conversion (atoi).
# include <algorithm>   // Algorithms library, provides sorting functions used in the code.

class PmergeMe
{
private:
    // Containers
    std::vector<int>    _vector;
    std::deque<int>     _deque;
    std::deque<int>     _unsorted;
    // Variables
    int     size;
    double _vectorSortingTime;
    double _dequeSortingTime;
    // Member Functions
    void    parseArgs(int argc, char **argv);
    // Sorting Functions
    void    mergeVector(std::vector<int> &arr, int left, int mid, int right);
    void    insertionSortVector(std::vector<int> &arr, int left, int right);    
    void    mergeInsertVectorSort(std::vector<int> &arr, int left, int right);
    // Sorting Functions
    void    mergeDeque(std::deque<int> &arr, int left, int mid, int right);
    void    insertionSortDeque(std::deque<int> &arr, int left, int right);
    void    mergeInsertDequeSort(std::deque<int> &arr, int left, int right);
    // Time Measurement Functions
    void    measureSortingTime();
    // Utility Functions
    int     calculateThreshold(int size);
    bool    isSortedDeque(std::deque<int> &arr);
    bool    isSortedVector(std::vector<int> &arr);

public:
    // Constructors
    PmergeMe();
    PmergeMe(PmergeMe const &copy);
    PmergeMe(int argc, char **argv);
    // Destructor
    ~PmergeMe();
    // Operator Overloads
    PmergeMe &operator=(PmergeMe const &copy);
    // Member Functions
    void run();
    void displayContainers();
};

#endif // PMERGEME_HPP
