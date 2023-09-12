/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:05:48 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 15:05:49 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
// Default Constructor
RPN::RPN() : expression(""), result(0) {}
// Operator Overloads
RPN &RPN::operator=(RPN const &rhs) {
    if (this != &rhs) {
        this->expression = rhs.expression;
        this->result = rhs.result;
    }
    return (*this);
}
// Copy Constructor
RPN::RPN(RPN const &copy) : expression(copy.expression), result(copy.result) {}
// Deconstructor
RPN::~RPN() {}
// Constructor
RPN::RPN(const std::string &expres) : expression(expres) {}

bool    RPN::isNumber(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) == false)
            return (false);
    }
    return (true);
}

bool    RPN::isOperator(const std::string &str)
{
    if (str.length() != 1)
        return (false);
    if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
        return (true);
    return (false);
}

int     RPN::performOperation(int operand1, int operand2, const std::string &op)
{
    if (op == "+")
        return (operand1 + operand2);
    else if (op == "-")
        return (operand1 - operand2);
    else if (op == "*")
        return (operand1 * operand2);
    else if (op == "/")
        return (operand1 / operand2);
    return (0);
}

bool RPN::evaluate()
{
    // Tokenize the expression
    std::string token;
    // String stream object to tokenize the expression
    std::stringstream ss(this->expression);
    // While there are tokens to read (skips whitespace by default)
    while (ss >> token)
    {
        // Uncomment this line to see the tokens
        // std::cout << "Token: " << token << std::endl; // Add this line

        // If the token is a number, push it onto the list
        if (this->isNumber(token))
            this->operands.push_back(std::atoi(token.c_str())); // Use push_back() for adding to the list
        // If the token is an operator, pop two operands from the list, perform the operation, and push the result onto the list
        else if (this->isOperator(token))
        {
            // If there are less than two operands in the list, the expression is invalid
            if (this->operands.size() < 2)
            {
                std::cerr << "Error: Not enough operands" << std::endl;
                return (false);
            }
            int operand2 = this->operands.back(); // Use back() to access the last element
            this->operands.pop_back(); // Use pop_back() to remove the last element
            int operand1 = this->operands.back(); // Use back() to access the last element
            this->operands.pop_back(); // Use pop_back() to remove the last element
            // Perform the operation
            int resultValue = this->performOperation(operand1, operand2, token);

            // Uncomment this line to see the operation being performed
            // std::cout << "Operation: " << operand1 << " " << token << " " << operand2 << " = " << resultValue << std::endl;

            // Push the result onto the back of the list
            this->operands.push_back(resultValue);
        }
        else
        {
            // If the token is not a number or operator, the expression is invalid
            std::cerr << "Error: Invalid token: " + token << std::endl;
            // Reset the result to avoid returning an invalid result
            this->result = 0;
            return (false);
        }
    }
    // If there are more than one operands when the evaluation is done, the expression is invalid
    if (this->operands.size() != 1)
    {
        std::cerr << "Error: Too many operands" << std::endl;
        return false;
    }
    // Set the result
    this->result = this->operands.back(); // Use back() to access the result
    return (true);
}
// Return the result of the expression
int     RPN::getResult() const
{
    return (this->result);
}