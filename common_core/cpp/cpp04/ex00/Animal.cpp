/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:49:58 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/27 17:24:14 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("")
{
	std::cout << "Default constructor Animal " << this->_type << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Constructor Animal " << this->_type << std::endl;
}

Animal::Animal(Animal const &a): _type(a._type)
{
	std::cout << "Copy constructor Animal " << this->_type << std::endl;
}

Animal::~Animal()
{
	std::cout << "Default destructor Animal " << this->_type << std::endl;
}

Animal&		Animal::operator=(Animal const &a)
{
	std::cout << "Copy assignment operator Animal" << std::endl;
	this->_type = a._type;
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->_type);
}

void		Animal::setType(std::string type)
{
	this->_type = type;
}

void		Animal::makeSound() const
{
	std::cout << "Yikes" << std::endl;
}