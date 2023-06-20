/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:45:21 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/17 14:00:05 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <stdio.h>

int	main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c( Fixed( 15 ) );
	Fixed const d( Fixed( 9.04f ) / Fixed( 2.02f ) );
	Fixed const e;
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "1------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << "2------------" << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "3------------" << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << "4------------" << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << "5------------" << std::endl;
	std::cout << c - d << std::endl;
	std::cout << c / e << std::endl;	
}