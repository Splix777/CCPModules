/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:06:00 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:06:01 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        // Create an instance of PmergeMe with int as the data type
        PmergeMe pmerge(argc, argv);
        // Run the sorting and display the sorted container along with sorting time
        pmerge.run();
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    return (0);
}

/**
 * Key Takeaways:
 * 
 * 1. Implementation of Merge-Insert Sort: You will implement the
 * merge-insert sort algorithm to efficiently sort a sequence of
 * positive integers. This exercise reinforces your understanding
 * of sorting algorithms and their practical application.
 * 
 * 2. Container Usage: You'll work with various C++ containers
 * to store and manipulate data. Understanding the strengths
 * and weaknesses of different containers is essential for
 * efficient data management.
 * 
 * 3. Performance Measurement: You'll measure and display the
 * time taken by different containers to sort the integer
 * sequence. This helps you compare the efficiency of containers
 * for different tasks and highlights the impact of data
 * structure choices on program performance.
 * 
 * 4. Error Handling: You'll handle error cases, such as
 * invalid input arguments, and display appropriate error
 * messages. This practice improves your error-handling
 * skills in C++.
 * 
 * Overall, this exercise promotes good programming practices,
 * algorithm implementation, container selection, and
 * performance measurement in C++, preparing you to make
 * informed choices when working on real-world projects
 * involving data manipulation and sorting.
 */

/**************************************
1. std::vector:

Characteristics:
- Dynamic array-based container.
- Fast random access to elements.
- Efficient contiguous memory allocation.

Pros:
- Fast random access.
- Efficient for appending elements to the end.
- Good cache locality due to contiguous memory.

Cons:
- Slower insertion in the middle.

Common Use Cases:
- When fast random access is required.
- When elements are frequently accessed and modified.
- When you don't need frequent insertions or deletions in the middle.

**************************************/

/**************************************
2. std::deque (Double-Ended Queue):

Characteristics:
- Double-ended queue-based container.
- Fast insertions and deletions at both ends.

Pros:
- Fast insertion and deletion at both ends.
- Dynamic memory allocation.

Cons:
- Slower random access.
- Slower insertion in the middle.

Common Use Cases:
- When you need efficient insertions and deletions at both ends.
- When implementing a double-ended queue.
- In scenarios with frequent front and back operations, like a sliding window.

**************************************/

/**************************************
3. std::list:

Characteristics:
- Doubly-linked list-based container.
- Fast insertions and deletions anywhere.

Pros:
- Fast insertions and deletions at any position.
- Stable iterators (not invalidated by insertions).

Cons:
- Slow random access.
- Higher memory overhead due to node structure.

Common Use Cases:
- When you need efficient insertions and deletions anywhere in the container.
- When iterators must remain valid after insertions.

**************************************/

/**************************************
4. std::set and std::multiset:

Characteristics:
- Associative containers based on a balanced binary search tree (typically Red-Black Tree).
- Automatically sorted elements.

Pros:
- Elements are automatically sorted.
- Efficient for searching and maintaining a sorted collection.

Cons:
- Slower insertion and deletion compared to vectors and lists.

Common Use Cases:
- When you need to maintain a sorted collection of unique elements (std::set).
- When you need to maintain a sorted collection with duplicate elements allowed (std::multiset).

**************************************/

/**************************************
5. std::map and std::multimap:

Characteristics:
- Associative containers with key-value pairs based on a balanced binary search tree.
- Automatically sorted by keys.

Pros:
- Efficient for key-based searches and maintaining sorted key-value pairs.

Cons:
- Slower insertion and deletion compared to vectors and lists.

Common Use Cases:
- When you need to maintain a sorted collection of key-value pairs with unique keys (std::map).
- When you need to maintain a sorted collection with duplicate keys allowed (std::multimap).

**************************************/

/**************************************
6. std::unordered_set and std::unordered_multiset:

Characteristics:
- Associative containers based on a hash table.
- Elements are not ordered; hashing determines the order.

Pros:
- Fast constant-time average insertion, search, and deletion.
- No sorting overhead.

Cons:
- Elements are not ordered.

Common Use Cases:
- When you need fast lookups and don't require sorted elements (std::unordered_set).
- When you need fast lookups with duplicate elements allowed (std::unordered_multiset).

**************************************/

/**************************************
7. std::unordered_map and std::unordered_multimap:

Characteristics:
- Associative containers with key-value pairs based on a hash table.
- Elements are not ordered; hashing determines the order.

Pros:
- Fast constant-time average operations for key-based lookups, insertions, and deletions.
- No sorting overhead.

Cons:
- Elements are not ordered.

Common Use Cases:
- When you need fast key-based lookups and don't require sorted key-value pairs (std::unordered_map).
- When you need fast key-based lookups with duplicate keys allowed (std::unordered_multimap).

**************************************/

