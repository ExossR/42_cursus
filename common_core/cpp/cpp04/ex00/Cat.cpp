/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:06:16 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/27 17:25:45 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Default constructor Cat " << this->_type << std::endl;
}

Cat::Cat(std::string type): Animal(type)
{
	std::cout << "Constructor Cat " << this->_type << std::endl;
}

Cat::Cat(Cat const &c)
{
	this->_type = c._type;
	std::cout << "Copy constructor Cat " << this->_type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Default destructor Cat " << this->_type << std::endl;
}

Cat&	Cat::operator=(Cat const &c)
{
	std::cout << "Copy assignment operator" << std::endl;
	this->_type = c._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}