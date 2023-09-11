#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>       // Include the standard stack container header.
#include <iterator>    // Include the iterator header.
#include <iostream>    // Include the input-output stream header.

// Declare a template class named MutantStack, which derives from std::stack<T>.
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    // Default constructor: Initializes the base std::stack<T> constructor.
    MutantStack() : std::stack<T>() {}

    // Copy constructor: Initializes the base std::stack<T> constructor using another MutantStack.
    MutantStack(MutantStack const &other) : std::stack<T>(other) {}

    // Assignment operator: Allows assigning one MutantStack to another.
    MutantStack &operator=(MutantStack const &other)
    {
        if (this != &other)
        {
            // Calls the base class's assignment operator to copy the contents.
            std::stack<T>::operator=(other);
        }
        return (*this);
    }

    // Destructor: Outputs a message when the MutantStack is destroyed.
    ~MutantStack()
    {
        std::cout << "MutantStack destructor called!" << std::endl;
    }

    // Define iterator and reverse_iterator types for the MutantStack.
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

    // Returns an iterator pointing to the beginning of the underlying container.
    iterator begin() { return (this->c.begin()); }

    // Returns an iterator pointing to the end of the underlying container.
    iterator end() { return (this->c.end()); }

    // Returns a reverse iterator pointing to the last element of the underlying container.
    reverse_iterator rbegin() { return (this->c.rbegin()); }

    // Returns a reverse iterator pointing to the element preceding the first element of the underlying container.
    reverse_iterator rend() { return (this->c.rend()); }
};

#endif
