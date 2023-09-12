/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:44:15 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:44:18 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>

class Zombie
{
private:
    std::string _name;

public:
    Zombie(std::string name);
    ~Zombie(void);
    void announce(void);
};

void    randomChump(std::string name);
Zombie  *newZombie(std::string name);
