#pragma once

#include <iostream>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:
        Contact();
        ~Contact();
        // Setters
        void    setFirstName();
        void    setLastName();
        void    setNickname();
        void    setPhoneNumber();
        void    setDarkestSecret();
        // Getters
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
        // Member functions
        int correctPhoneFormat(std::string input) const;
};