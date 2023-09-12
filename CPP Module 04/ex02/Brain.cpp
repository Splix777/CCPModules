/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:27 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:28 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "A brain has been constructed and filled with ideas" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "A brain has been constructed and filled with ideas" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "A brain has been destroyed\n";
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}

const std::string Brain::getIdeas(size_t i)
{
	if (i < 100)
		return (this->ideas[i]);
	else
		return ("Invalid index");
}

const std::string *Brain::getIdeasPointer(size_t i)
{
	if (i < 100)
		return (&this->ideas[i]);
	else
		return (NULL);
}

void Brain::setIdeas(size_t i, std::string idea)
{
	if (i < 100)
		this->ideas[i] = idea;
	else
		std::cout << "Invalid index" << std::endl;
}