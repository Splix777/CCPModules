#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

# define MAX_FLOOR_ITEMS 10

class Character;

class Floor
{
    private:
        AMateria    *_inventory[MAX_FLOOR_ITEMS];
        int         _nbItems;

        Floor(Floor const &copy);
        Floor & operator=(Floor const &copy);
    
    public:
        Floor();
        ~Floor();

        void    dropItem(AMateria *m, ICharacter &target);
        void    pickUpItem(std::string const &itemName, ICharacter &target);
        int     getNbItems() const;
        void    printInventory() const;
};


#endif