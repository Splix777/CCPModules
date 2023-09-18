/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:04:15 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/18 17:59:59 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename Function>
void iter(T *array, size_t length, Function func)
{
    size_t  i;

    i = 0;
    if (!array || !func)
        return ;
    while (i < length)
    {
        func(array[i]);
        i++;
    }
}

#endif