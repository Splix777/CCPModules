#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "Floor.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		AMateria			*_inventory[4];
		std::string const	_name;
		Floor				_floor;

		Character();
	public:
		Character(std::string name);
		~Character();

		Character(Character const &copy);
		Character & operator=(Character const &copy);

		std::string const &getName() const;

		void equip(AMateria *m);
		void pickUpFromFloor(std::string const &type);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		AMateria	*getMateria(int idx);

		void		printInventory() const;
};

#endif