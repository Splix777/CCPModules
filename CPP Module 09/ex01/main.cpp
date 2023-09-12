/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:05:43 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:05:44 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return (1);
    }
    RPN rpn(argv[1]);
    if (!rpn.evaluate())
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    std::cout << "Result: " << rpn.getResult() << std::endl;
    return (0);
}

/*
RPN stands for Reverse Polish Notation, which is a way to represent mathematical
expressions. In basic terms, RPN is an alternative to the more common infix notation
(the way we typically write mathematical expressions, e.g., "3 + 4").

In RPN, you write the expression in a way that makes it easy to evaluate using a
stack-based approach. Here are the basic principles of RPN:

1. No Parentheses: RPN expressions don't use parentheses to specify the order of
operations. Instead, the order of operations is determined by the
position of the operators.

2.Postfix Notation: In RPN, operators come after their operands. For example,
instead of writing "3 + 4," you would write "3 4 +." This means "add 3 and 4."

3. Stack-Based Evaluation: To evaluate an RPN expression, you start from the
left and move to the right, reading each token (number or operator). When you
encounter a number, you push it onto a stack. When you encounter an operator,
you pop the required number of operands from the stack, perform the operation,
and then push the result back onto the stack.

4. Simplicity: RPN eliminates the need for complex rules about operator precedence
and parentheses. The order of operations is determined by the order of tokens
in the expression.

Here's a simple example in both infix and RPN notations:

    Infix Notation: 3 + 4 * 2
    RPN Notation: 3 4 2 * +

Here's how you would evaluate the RPN expression:

1. Push 3 onto the stack.

2. Push 4 onto the stack.

3. Push 2 onto the stack.

4. When you encounter *, it's an operator, so pop 2 and 4 from the stack,
   perform the multiplication, and push 8 back onto the stack.

5. When you encounter +, it's an operator, so pop 3 and 8 from the stack,
    perform the addition, and push 11 back onto the stack.

6. The expression is complete, so the result is 11.

RPN is often used in calculators because it's more straightforward to implement
the evaluation logic using a stack, as shown in your exercise.

*/