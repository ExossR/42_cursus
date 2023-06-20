/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:16:57 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/18 14:55:15 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a = ClapTrap("Will Smith");
	ClapTrap b = ClapTrap("Chris Rock");
	int i = 0;

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	a.setAttackDamage(5);
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	std::cout << "------------------" << std::endl;
	std::cout << a.getName() << " :" << std::endl 
				<< "hp = " << a.getHitPoints() << std::endl
				<< "ep = " << a.getEnergyPoints() << std::endl;
	std::cout << b.getName() << " :" << std::endl 
				<< "hp = " << b.getHitPoints() << std::endl
				<< "ep = " << b.getEnergyPoints() << std::endl;
	std::cout << "------------------" << std::endl;
	b.attack(a.getName());
	a.takeDamage(b.getAttackDamage());
	b.beRepaired(2);
	while (i < 11)
	{
		b.attack(a.getName());
		if (b.getEnergyPoints() > 0)
			a.takeDamage(b.getAttackDamage());
		i++;
	}
	std::cout << "------------------" << std::endl;
	a.setAttackDamage(6);
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	std::cout << "------------------" << std::endl;
	std::cout << a.getName() << " :" << std::endl 
				<< "hp = " << a.getHitPoints() << std::endl
				<< "ep = " << a.getEnergyPoints() << std::endl;
	std::cout << b.getName() << " :" << std::endl 
				<< "hp = " << b.getHitPoints() << std::endl
				<< "ep = " << b.getEnergyPoints() << std::endl;
}