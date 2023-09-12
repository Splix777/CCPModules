/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:05:51 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:05:52 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>		// Provides string manipulation capabilities.
# include <list>		// Provides the std::list container used to store operands.
# include <sstream>		// Provides the std::stringstream class for tokenization.
# include <iostream>	// Provides input and output stream functionalities.
# include <cstdlib> 	// Provides functions like std::atoi for string to integer conversion.

/* Reverse Polish Notation (RPN) is a mathematical notation in which
   every operator follows all of its operands. */
class RPN {
    public:
        // Constructors
        RPN();
        RPN(const std::string &expres);
        RPN(RPN const &copy);
        // Destructor
        ~RPN();
        // Operator Overloads
        RPN &operator=(RPN const &rhs);
        // Member Functions
        // Evaluate the expression and return true if the expression is valid
        bool evaluate();
        // Return the result of the expression
        int getResult() const;

    private:
        /*  Encapsulation of the class
            Information Hiding
            Prevents the user from accessing the private members */
        bool isNumber(const std::string &str);
        bool isOperator(const std::string &str);
        int performOperation(int operand1, int operand2, const std::string &op);

        // Holds the expression
        std::string expression;
        // Holds the result of the expression
        int result;
        // Holds the operands in a list container
        std::list<int> operands;
};

#endif // RPN_HPP
