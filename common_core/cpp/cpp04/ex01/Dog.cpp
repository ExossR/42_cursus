/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:59:51 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/27 17:29:44 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Default constructor Dog " << this->_type << std::endl;
}

Dog::Dog(std::string type): Animal(type)
{
	this->_brain = new Brain();
	std::cout << "Constructor Dog " << this->_type << std::endl;
}

Dog::Dog(Dog const &d)
{
	this->_type = d._type;
	this->_brain = d._brain;
	std::cout << "Copy constructor Dog " << this->getType() << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Default destructor Dog " << this->_type << std::endl;
}

Dog&	Dog::operator=(Dog const &d)
{
	std::cout << "Copy assignment operator" << std::endl;
	this->_type = d._type;
	this->_brain = new Brain();
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Wouaf!" << std::endl;
}