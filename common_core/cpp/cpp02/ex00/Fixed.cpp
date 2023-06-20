/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:45:44 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/12 16:46:29 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _x(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(Fixed &fixed): _x(fixed._x)
{
	std::cout << "Copy constructor called." << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed&	Fixed::operator=(Fixed &fixed)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->_x = fixed._x;
	return (*this);
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_x);
}

void	Fixed::setRawBits(int const raw)
{
	this->_x = raw;
}