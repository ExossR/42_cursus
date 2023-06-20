/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:03:04 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/03 13:30:29 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <unistd.h>

Zombie	*zombieHorde(int N, std::string name);

int	main()
{
	int		n = 5;
	Zombie	*tab = zombieHorde(n, "oui");
	int		i = 0;

	std::cout << "--------------------" << std::endl;
	while (i < n)
	{
		tab[i].announce();
		i++;	
	}
	std::cout << "--------------------" << std::endl;
	i = 0;
	while (i < n)
	{
		tab[i].~Zombie();
		i++;
	}
	//system("leaks zombie");
}