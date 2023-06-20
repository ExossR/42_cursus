/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:44:14 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/12 16:45:12 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	private:
		int					_x;
		static const int	_bit = 8;
		
	public:
		Fixed();
		Fixed(Fixed &fixed);
		~Fixed();
		Fixed& operator=(Fixed &fixed);
		int		getRawBits() const;
		void	setRawBits(int const raw);
};