/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:51:12 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:51:22 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
# define INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
# define ERROR "This is unacceptable! I want to speak to the manager now."

class Harl
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:
    Harl( void );
    ~Harl( void );
    void complain(std::string level);
};

#endif
