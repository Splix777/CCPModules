/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaPhone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:41:33 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:41:36 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        int i = 1;
        while (i < argc)
        {
            int j = 0;
            while (argv[i][j])
            {
                std::cout << (char)std::toupper(argv[i][j]);
                j++;
            }
            if (i != argc - 1)
                std::cout << " ";
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}
