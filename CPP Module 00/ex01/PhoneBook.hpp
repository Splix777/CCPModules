/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:42:23 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:42:24 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <unistd.h>
#include "Contact.hpp"

class Contact;

class PhoneBook
{
    private:
        Contact    contact[8];
        int        index;
        bool       full;

    public:
        PhoneBook();
        ~PhoneBook();

        void    addContact();
        void    searchContact();
        void    printContact(int index) const;
        Contact getContact(int index) const;
};
