#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animals[10] ;
	int i;
	std::cout << "-----------------------------------" << std::endl;
	for (i = 0; i < 5; i++) {
		animals[i] = new Dog();
	}
	std::cout << "-----------------------------------" << std::endl;
	for (; i < 10; i++) {
		animals[i] = new Cat();
	}
	std::cout << "-----------------------------------" << std::endl;
	for (i = 0; i < 10; i++) {
		delete animals[i];
	}
	std::cout << "-----------------------------------" << std::endl;
	Dog* dog = new Dog();
	std::cout << "-----------------------------------" << std::endl;
	Dog* dog2 = new Dog(*dog);
	std::cout << "-----------------------------------" << std::endl;
	dog->getBrain()->setIdea(0, "Chase tail");
	dog->getBrain()->setIdea(1, "Bark at mailman");
	std::cout << "-----------------------------------" << std::endl;
	*dog2 = *dog;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << dog2->getBrain()->getIdea(0) << std::endl;
	std::cout << dog2->getBrain()->getIdea(1) << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	dog->getBrain()->setIdea(0, "Bite mailman");
	dog->getBrain()->setIdea(1, "Smell Poop");
	std::cout << "-----------------------------------" << std::endl;
	std::cout << dog->getBrain()->getIdea(0) << std::endl;
	std::cout << dog->getBrain()->getIdea(1) << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << dog2->getBrain()->getIdea(0) << std::endl;
	std::cout << dog2->getBrain()->getIdea(1) << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	delete dog;
	delete dog2;

	return (0);
}