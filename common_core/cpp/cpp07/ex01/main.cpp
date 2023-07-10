/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:09:41 by asahonet          #+#    #+#             */
/*   Updated: 2023/06/29 17:52:15 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	printSquare(int n)
{
	int	res = n * n;
	std::cout << "Square of " << n << " equal to " << res << std::endl;
}

void	printMultpBy5(int n)
{
	int	res = n * 5;
	std::cout << "MultpBy5 of " << n << " equal to " << res << std::endl;
}

void	printAddOneToChar(char c)
{
	char	tmp = c;
	c += 1;
	std::cout << "Old :" << tmp << " ; New :" << c << std::endl;
}

int	main() 
{
	int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	::iter(arr, 9, printSquare);
	::iter(arr, 9, printMultpBy5);

	char	*s = "Bonjour.";

	::iter(s, strlen(s), printAddOneToChar);
}