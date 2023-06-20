/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:03:40 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/03 13:29:34 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int		i = 0;
	Zombie	*tab;

	tab = new Zombie[N];
	while (i < N)
	{
		tab[i].set_name(name);
		i++;
	}
	return (tab);
}