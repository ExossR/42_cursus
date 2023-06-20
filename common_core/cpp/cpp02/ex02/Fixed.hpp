/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:44:14 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/17 12:16:01 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_x;
		static const int	_bit = 8;
		
	public:
		Fixed();
		Fixed(Fixed const &fixed);
		Fixed(const int x);
		Fixed(const float x);
		~Fixed();
		
		Fixed& 	operator=(Fixed const &fixed);
		Fixed&	operator+(Fixed const &f);
		Fixed&	operator-(Fixed const &f);
		Fixed&	operator*(Fixed const &f);
		Fixed&	operator/(Fixed const &f);
		Fixed&	operator++(); // pre-increment
		Fixed&	operator--(); // pre-decrement
		Fixed	operator++(int); // post-increment
		Fixed	operator--(int); // post-decrement

		static Fixed&	min(Fixed &f1, Fixed &f2);
		static const Fixed&	min(Fixed const	 &f1, Fixed const &f2);
		static Fixed&	max(Fixed &f1, Fixed &f2);
		static const Fixed&	max(Fixed const &f1, Fixed const &f2);
		
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream&	operator<<(std::ostream& os, Fixed const &fixed);
bool			operator<(Fixed const &f1, Fixed const &f2);
bool			operator>(Fixed const &f1, Fixed const &f2);
bool			operator<=(Fixed const &f1, Fixed const &f2);
bool			operator>=(Fixed const &f1, Fixed const &f2);
bool			operator==(Fixed const &f1, Fixed const &f2);
bool			operator!=(Fixed const &f1, Fixed const &f2);
