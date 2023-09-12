/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:42:38 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:42:40 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>

// Utils
void    clearScreen();
// Displays
void    displayWelcome();
void    displayAdd();
// Prints
void    printShortenedContact(std::string str);
void    printFullContact(std::string str);

#endif
