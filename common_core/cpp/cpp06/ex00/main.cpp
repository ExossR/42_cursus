/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:09:14 by asahonet          #+#    #+#             */
/*   Updated: 2023/06/29 10:03:57 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "You need to put only one argument." << std::endl;
		return (1);
	}
	ScalarConverter	sc = ScalarConverter();

	sc.convert(argv[1]);
}