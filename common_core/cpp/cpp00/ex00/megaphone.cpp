/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:21:14 by asahonet          #+#    #+#             */
/*   Updated: 2023/03/29 09:57:16 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	toupper(char c)
{
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}

int	main(int argc, char **argv)
{
	int i = 1;
	int	j;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBREARABLE FEEDBACK NOISE *";
	else
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				std::cout << toupper(argv[i][j]);
				j++;
			}
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
