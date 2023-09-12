/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:45:29 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:45:30 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>

class Zombie
{
private:
    std::string _name;

public:
    Zombie(std::string name);
    Zombie(void);
    ~Zombie(void);
    void announce(void);
    void giveName(std::string name);
};

Zombie  *newZombie(std::string name);
Zombie  *zombieHorde(int N, std::string name);
