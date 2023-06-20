/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:45:44 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/14 09:50:14 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _x(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(Fixed const &fixed): _x(fixed._x)
{
	std::cout << "Copy constructor called." << std::endl;
}

Fixed::Fixed(const int x)
{
	this->_x = x * (1 << this->_bit);
	std::cout << "Int constructor called." << std::endl;
}

Fixed::Fixed(const float x)
{
	this->_x = x * (1 << this->_bit);
	std::cout << "Float constructor called." << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->_x = fixed._x;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
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

float	Fixed::toFloat() const
{
	return ((float) this->_x / (float)(1 << this->_bit));
}

int		Fixed::toInt() const
{
	return ((int) this->_x / (1 << this->_bit));
}