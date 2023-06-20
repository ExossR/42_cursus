/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:45:44 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/17 12:18:01 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _x(0)
{
	//std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(Fixed const &fixed): _x(fixed._x)
{
	//std::cout << "Copy constructor called." << std::endl;
}

Fixed::Fixed(const int x)
{
	this->_x = x * (1 << this->_bit);
	//std::cout << "Int constructor called." << std::endl;
}

Fixed::Fixed(const float x)
{
	this->_x = x * (1 << this->_bit);
	//std::cout << "Float constructor called." << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called." << std::endl;
}

/*---------------------------------------------------------------*/

Fixed&	Fixed::operator=(Fixed const &fixed)
{
	//std::cout << "Copy assignment operator called." << std::endl;
	this->_x = fixed._x;
	return (*this);
}

Fixed&	Fixed::operator+(Fixed const &fixed)
{
	this->_x = (this->toFloat() + fixed.toFloat()) * (1 << this->_bit);
	return (*this);
}

Fixed&	Fixed::operator-(Fixed const &fixed)
{
	this->_x = (this->toFloat() - fixed.toFloat()) * (1 << this->_bit);
	return (*this);
}

Fixed&	Fixed::operator*(Fixed const &fixed)
{
	this->_x = (this->toFloat() * fixed.toFloat()) * (1 << this->_bit);
	return (*this);
}

Fixed&	Fixed::operator/(Fixed const &fixed)
{
	this->_x = (this->toFloat() / fixed.toFloat()) * (1 << this->_bit);
	return (*this);
}

Fixed&	Fixed::operator++()
{
	this->_x = (this->toFloat() + 0.00390625) * (1 << this->_bit);
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->_x = (this->toFloat() - 0.00390625) * (1 << this->_bit);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(this->toFloat());
	this->operator++();
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(this->toFloat());
	this->operator--();
	return (tmp);
}

/*---------------------------------------------------------------*/

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

/*---------------------------------------------------------------*/

std::ostream&	operator<<(std::ostream& os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool			operator<(Fixed const &f1, Fixed const &f2)
{
	if (f1.toFloat() < f2.toFloat())
		return (true);
	return (false);
}

bool			operator>(Fixed const &f1, Fixed const &f2)
{
	if (f1.toFloat() > f2.toFloat())
		return (true);
	return (false);
}

bool			operator<=(Fixed const &f1, Fixed const &f2)
{
	if (f1.toFloat() <= f2.toFloat())
		return (true);
	return (false);
}

bool			operator>=(Fixed const &f1, Fixed const &f2)
{
	if (f1.toFloat() >= f2.toFloat())
		return (true);
	return (false);
}

bool			operator==(Fixed const &f1, Fixed const &f2)
{
	if (f1.toFloat() == f2.toFloat())
		return (true);
	return (false);
}

bool			operator!=(Fixed const &f1, Fixed const &f2)
{
	if (f1.toFloat() != f2.toFloat())
		return (true);
	return (false);
}

/*---------------------------------------------------------------*/

Fixed&	Fixed::min(Fixed &f1, Fixed &f2)
{
	if (operator<=(f1, f2) == true)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min(Fixed const	 &f1, Fixed const &f2)
{
	if (operator<=(f1, f2) == true)
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed &f1, Fixed &f2)
{
	if (operator>=(f1, f2) == true)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (operator>=(f1, f2) == true)
		return (f1);
	return (f2);
}