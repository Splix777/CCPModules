#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_inventory[4];
		
	public:
		MateriaSource();
		~MateriaSource();

		MateriaSource(MateriaSource const &copy);
		MateriaSource & operator=(MateriaSource const &copy);

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const &type);
		void printInventory() const;
};

#endif