/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:21:01 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/03 13:00:48 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	Zombie z = Zombie("Julien"); // tas (heap)
	Zombie* x = newZombie("Leo"); // pile (stack)
	z.announce();
	x->announce();
	randomChump("Arnaud");
	z.~Zombie();
	x->~Zombie();
}