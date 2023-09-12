/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:46:21 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:46:23 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *horde;
    int     i;

    i = 0;
    if (N <= 0)
        return (NULL);
    horde = new Zombie[N];
    while (i < N)
    {
        horde[i].giveName(name);
        i++;
    }
    return (horde);
}
