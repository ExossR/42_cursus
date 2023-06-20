/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:44:14 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/13 13:28:23 by asahonet         ###   ########.fr       */
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
		Fixed& 					operator=(Fixed const &fixed);
		int						getRawBits() const;
		void					setRawBits(int const raw);
		float					toFloat() const;
		int						toInt() const;
};

std::ostream&	operator<<(std::ostream& os, Fixed const &fixed);