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