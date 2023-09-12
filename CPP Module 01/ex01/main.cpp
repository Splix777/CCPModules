/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:46:07 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 16:42:12 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
    int     N;

    if (argc == 2)
    {
        N = atoi(argv[1]);
        Zombie  *horde;
        horde = zombieHorde(N, "Bobs");
        for (int i = 0; i < N; i++)
            horde[i].announce();
        delete[] horde;
    }
    else
        std::cout << "Usage: ./zombieHorde [number of zombies]" << std::endl;
    return (0);    
}
