/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:05:15 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/18 18:43:08 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    // PDF Provided Main

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Testing with a list instead of MutantStack" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    std::list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);
    std::cout << lstack.back() << std::endl;
    lstack.pop_back();
    std::cout << lstack.size() << std::endl;
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    //[...]
    lstack.push_back(0);
    std::list<int>::iterator iit = lstack.begin();
    std::list<int>::iterator iite = lstack.end();
    ++it;
    --it;
    while (iit != iite)
    {
        std::cout << *iit << std::endl;
        ++iit;
    }
    std::list<int> e(lstack);


    return (0);
}
