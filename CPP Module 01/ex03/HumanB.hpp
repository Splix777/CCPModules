/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:50:26 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:51:36 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
    std::string _name;
    Weapon      *_weapon;
public:
    HumanB(std::string name);
    ~HumanB();
    void    attack( void );
    void    setWeapon(Weapon &weapon);
};

#endif