/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:05:21 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/27 11:50:39 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>       // Include the standard stack container header.
#include <list>        // Include the standard list container header.
#include <iterator>    // Include the iterator header.
#include <iostream>    // Include the input-output stream header.

// Declare a template class named MutantStack, which derives from std::stack<T>.
template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(MutantStack const &other) : std::stack<T>(other) {}
        MutantStack &operator=(MutantStack const &other)
        {
            if (this != &other)
            {
                std::stack<T>::operator=(other);
            }
            return (*this);
        }

        ~MutantStack() {}
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

        iterator begin() { return (this->c.begin()); }
        iterator end() { return (this->c.end()); }
        reverse_iterator rbegin() { return (this->c.rbegin()); }
        reverse_iterator rend() { return (this->c.rend()); }
};

#endif
