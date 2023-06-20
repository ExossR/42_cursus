/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:16:57 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/25 15:02:51 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ClapTrap a = ClapTrap("Will Smith");
	ScavTrap b = ScavTrap("Chris Rock");
	int i = 0;
	int	j;

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	a.setAttackDamage(6);
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	std::cout << "X----------------X" << std::endl;
	std::cout << a.getName() << " :" << std::endl 
				<< "hp = " << a.getHitPoints() << std::endl
				<< "ep = " << a.getEnergyPoints() << std::endl;
	std::cout << b.getName() << " :" << std::endl 
				<< "hp = " << b.getHitPoints() << std::endl
				<< "ep = " << b.getEnergyPoints() << std::endl;
	std::cout << "X----------------X" << std::endl;
	b.beRepaired(2);
	while (i < 11)
	{
		j = a.getEnergyPoints();
		a.attack(b.getName());
		if (j > 0)
		{
			b.takeDamage(a.getAttackDamage());
			std::cout << "------------------" << std::endl;
			std::cout << b.getName() << " :" << std::endl 
				<< "hp = " << b.getHitPoints() << std::endl
				<< "ep = " << b.getEnergyPoints() << std::endl;
			std::cout << "------------------" << std::endl;
		}
		i++;
	}
	std::cout << "X----------------X" << std::endl;
	b.attack(a.getName());
	a.takeDamage(b.getAttackDamage());
	std::cout << "X----------------X" << std::endl;
	std::cout << a.getName() << " :" << std::endl 
				<< "hp = " << a.getHitPoints() << std::endl
				<< "ep = " << a.getEnergyPoints() << std::endl;
	std::cout << b.getName() << " :" << std::endl 
				<< "hp = " << b.getHitPoints() << std::endl
				<< "ep = " << b.getEnergyPoints() << std::endl;
	std::cout << "X----------------X" << std::endl;
	b.guardGate();
	std::cout << "X----------------X" << std::endl;
}