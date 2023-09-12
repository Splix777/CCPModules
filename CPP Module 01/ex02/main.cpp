/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:47:25 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:47:26 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
    std::string brain;
    std::string& brainRef = brain;

    brain = "HI THIS IS BRAIN";
    const char* strPtr = brain.c_str();

    std::cout << "String: " << brain << std::endl;
    std::cout << "String Address: " << &brain << std::endl;
    std::cout << "String Length: " << brain.length() << std::endl;
    std::cout << "String Pointer: " << strPtr << std::endl;
    std::cout << "Pointer Value Address: " << (void*)strPtr << std::endl;  // Cast to void* to print pointer value
    std::cout << "String Ref: " << brainRef << std::endl;
    std::cout << "Reference Value Address: " << &brainRef << std::endl;  // Address of the reference itself
    std::cout << "String Length via Ref: " << brainRef.length() << std::endl;

    return 0;
}
