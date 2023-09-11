#pragma once

#ifndef Brain_HPP
# define Brain_HPP

# include "Animal.hpp"

class Brain
{
    private:
        std::string *ideas;

    public:
        Brain();
        Brain(const Brain &copy);
        ~Brain();
        Brain &operator=(const Brain &copy);
        std::string getIdea(int i);
        void        setIdea(int i, std::string idea);
};

#endif