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
    template <typename Container>
    void    mergeVectorSort(Container &container);
    // Sorting Functions
    template <typename Container>
    void    mergeDequeSort(Container &container);
    // Time Measurement Functions
    template <typename Container>
    void    measureSortingTime(Container &container);

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
