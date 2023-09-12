/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:57:35 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:57:36 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	this->ideas = new std::string[100];
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain& Brain::opersator=(const Brain &copy)
{
	if (this != &copy) {
		delete[] this->ideas;
		this->ideas = new std::string[100];
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	delete[] this->ideas;
}

std::string Brain::getIdea(int index)
{
	return (this->ideas)[index];
}

void Brain::setIdea(int i, std::string idea)
{
	(this->ideas)[i] = idea;
}