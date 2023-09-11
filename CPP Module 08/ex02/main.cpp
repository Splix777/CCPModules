#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mmstack;

    // Push some values onto the MutantStack
    mmstack.push(5);
    mmstack.push(17);
    mmstack.push(3);
    mmstack.push(42);

    // Using regular iteration
    std::cout << "Regular Iteration:" << std::endl;
    MutantStack<int>::iterator it;
    for (it = mmstack.begin(); it != mmstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using reverse iteration
    std::cout << "Reverse Iteration:" << std::endl;
    MutantStack<int>::reverse_iterator rit;
    for (rit = mmstack.rbegin(); rit != mmstack.rend(); ++rit)
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Top element and size
    std::cout << "Top element: " << mmstack.top() << std::endl;
    std::cout << "Stack size: " << mmstack.size() << std::endl;

    // Pop elements
    mmstack.pop();
    mmstack.pop();

    std::cout << "After popping two elements, stack size: " << mmstack.size() << std::endl;

    // Using iterator to print after popping
    std::cout << "Stack after popping two elements:" << std::endl;
    for (it = mmstack.begin(); it != mmstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // PDF Provided Main

    // MutantStack<int> mstack;
    // mstack.push(5);
    // mstack.push(17);
    // std::cout << mstack.top() << std::endl;
    // mstack.pop();
    // std::cout << mstack.size() << std::endl;
    // mstack.push(3);
    // mstack.push(5);
    // mstack.push(737);
    // //[...]
    // mstack.push(0);
    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    // while (it != ite)
    // {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }
    // std::stack<int> s(mstack);


    return (0);
}
