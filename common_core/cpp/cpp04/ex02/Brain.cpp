/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:38:53 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/27 17:48:34 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor Brain" << std::endl;
}

Brain::Brain(Brain const &b)
{
	for (unsigned int i = 0; i < this->_ideas->size(); i++)
		this->_ideas[i] = b._ideas[i];
	std::cout << "Copy constructor Brain" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Default destructor Brain" << std::endl;
}

Brain&	Brain::operator=(Brain const &b)
{
	for (unsigned int i = 0; i < this->_ideas->size(); i++)
		this->_ideas[i] = b._ideas[i];
	std::cout << "Copy assignment operator" << std::endl;
	return (*this);
}