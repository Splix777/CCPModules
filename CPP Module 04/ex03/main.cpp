#include <iostream>
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// int main()
// {
// IMateriaSource* src = new MateriaSource();
// src->learnMateria(new Ice());
// src->learnMateria(new Cure());
// ICharacter* me = new Character("me");
// AMateria* tmp;
// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// ICharacter* bob = new Character("bob");
// me->use(0, *bob);
// me->use(1, *bob);
// delete bob;
// delete me;
// delete src;
// return 0;
// }

int	main()
{
	{
		// Constructors
		std::cout << "\033[0;31mCONSTRUCTOR TESTS:\033[0m" << std::endl;
		std::cout << "-----------------------" << std::endl;

		// Create a MateriaSource
		MateriaSource MateriaBook;
		MateriaSource MateriaBook2(MateriaBook);
		MateriaBook2 = MateriaBook;
		std::cout << std::endl;

		// Create Materias
		Ice Ice;
		Cure Cure;
		std::cout << std::endl;

		// Create a Character
		Character Warlock("Warlock");
		Character Bob("Bob");
		Bob = Warlock;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		std::cout << "\033[0;31mMATERIA CREATION TESTS:\033[0m" << std::endl;
		std::cout << "-----------------------" << std::endl;

		// Create a MateriaSource
		MateriaSource MateriaBook;
		MateriaSource MateriaBook2(MateriaBook);
		std::cout << std::endl;

		// Create Materias
		std::cout << std::endl;

		// Learn Materias
		MateriaBook.learnMateria(new Ice());
		MateriaBook.learnMateria(new Cure());
		std::cout << std::endl;

		// Learn a NULL Materia
		MateriaBook.learnMateria(NULL);
		std::cout << std::endl;

		// Learn a Materia that already exists
		MateriaBook.learnMateria(new Ice());
		MateriaBook.learnMateria(new Cure());
		std::cout << std::endl;

		// See the MateriaSource's inventory
		MateriaBook.printInventory();
		std::cout << std::endl;
		MateriaBook2 = MateriaBook;
		std::cout << std::endl;
		MateriaBook2.printInventory();
		std::cout << std::endl;

		// Create a Materia from the MateriaSource
		AMateria *IceMateria = MateriaBook.createMateria("ice");
		AMateria *CureMateria = MateriaBook.createMateria("cure");
		delete IceMateria;
		delete CureMateria;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
    	std::cout << "\033[0;31mCHARACTER TESTS:\033[0m" << std::endl;
		std::cout << "-----------------------" << std::endl;

		// Create a MateriaSource
		MateriaSource MateriaBook;
		std::cout << std::endl;

		// Learn Materias
		MateriaBook.learnMateria(new Ice());
		MateriaBook.learnMateria(new Cure());
		std::cout << std::endl;

		// Create a Character
		Character Warlock("Warlock");
		Character Bob("Bob");
		std::cout << std::endl;

		// Equip Materias
		Warlock.equip(MateriaBook.createMateria("ice"));
		Warlock.equip(MateriaBook.createMateria("cure"));
		std::cout << std::endl;

		// Character Operator Overload Deep Copy
		Bob = Warlock;
		Bob.printInventory();
		std::cout << std::endl;

		// Equip a NULL Materia
		Warlock.equip(NULL);
		std::cout << std::endl;

		// Equip a Materia that already exists
		Warlock.equip(MateriaBook.createMateria("ice"));
		Warlock.equip(MateriaBook.createMateria("cure"));
		std::cout << std::endl;

		// See the Character's inventory
		Warlock.printInventory();
		std::cout << std::endl;

		// Use a Materia
		Warlock.use(0, Bob);
		Warlock.use(1, Bob);
		std::cout << std::endl;

		// Use a Materia that doesn't exist
		Warlock.use(2, Bob);
		std::cout << std::endl;

		// Use a Materia that hasn't been equipped
		Warlock.use(3, Bob);
		std::cout << std::endl;

		// Unequip a Materia
		Warlock.unequip(0);
		Warlock.unequip(1);
		std::cout << std::endl;

		// Unequip a Materia that doesn't exist
		Warlock.unequip(2);
		std::cout << std::endl;

		// Pick up a Materia from the floor
		Warlock.pickUpFromFloor("ice");
		std::cout << std::endl;

		// Try to pick up a Materia that doesn't exist
		Warlock.pickUpFromFloor("fire");
		std::cout << std::endl;

		// See the Character's inventory
		Warlock.printInventory();
		std::cout << std::endl;

		// See that Bob's inventory is not affected by Warlock's
		Bob.printInventory();
		std::cout << std::endl;

		// Use a Materia that has been unequipped
		Warlock.use(0, Bob);
		Warlock.use(1, Bob);
		std::cout << std::endl;
		
	}

	return (0);
}

	