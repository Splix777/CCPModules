/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:44 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/14 13:30:16 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Now that AAnimal::makeSound() is a pure virtual method, we cannot
	// instantiate an AAnimal object.  The following line will not compile:

	// const AAnimal	*animal = new AAnimal();
	// animal->makeSound();

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const AAnimal	*meta[10];
	// We can initialize an array of pointers to AAnimal objects, however.
	// Even thought AAnimal is an abstract class, we can still use it as a
	// pointer type.  We just can't instantiate an AAnimal object.
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Cat();
			if (meta[i] == NULL)
			{
				std::cerr << "Exiting process now";
				return(1);
			}
		}
		else
		{
			meta[i] = new Dog();
			if (meta[i] == NULL)
			{
				std::cerr << "Exiting process now";
				return(1);
			}
		}
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
		delete(meta[i]);

//THIS PART IS FOR TESTING DEEP COPY ↓

	std::cout << std::endl << std::endl;
	std::cout << "#### showing that the copy constructor creates a deep copy ####" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Dog *a = new Dog();
	// Cat *b = new Cat();
	if (a == NULL)
	{
		std::cerr << "Exiting the process now." << std::endl;
		return(1);
	}

	a->setIdeas("Smell the butt", 0);
	a->setIdeas("Pee on the floor", 1);
	a->setIdeas("Squirrel?????", 2);
	a->setIdeas("Bark at the mailman", 3);
	a->setIdeas("Destroy a pillow", 4);
	a->setIdeas("Do something that won't piss the humans off.", 101);

	Dog *b = new Dog(*a);
	std::cout << "Memory address of a: " << a << std::endl;
	std::cout << "Memory address of b: " << b << std::endl;
	// Cat *b = new Cat(*a);
	if (b == NULL)
	{
		std::cerr << "Exiting the process now." << std::endl;
		return(1);
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting a\033[0m" << std::endl;
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	a->getIdeas();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
	delete(a);
	std::cout << std::endl;

	std::cout << "\033[34mTesting b\033[0m" << std::endl;
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	b->getIdeas();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
	delete(b);

	return (0);
}

