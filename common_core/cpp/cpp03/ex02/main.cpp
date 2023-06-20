/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:16:57 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/25 15:38:20 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap a = ClapTrap("Will Smith");
	ScavTrap b = ScavTrap("Chris Rock");
	FragTrap c = FragTrap("Kevin Hart");
	int i = 0;
	int j;

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	a.setAttackDamage(6);
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	c.attack(b.getName());
	b.takeDamage(c.getAttackDamage());
	b.attack(c.getName());
	c.takeDamage(b.getAttackDamage());
	std::cout << "X----------------X" << std::endl;
	std::cout << a.getName() << " :" << std::endl 
				<< "hp = " << a.getHitPoints() << std::endl
				<< "ep = " << a.getEnergyPoints() << std::endl;
	std::cout << b.getName() << " :" << std::endl 
				<< "hp = " << b.getHitPoints() << std::endl
				<< "ep = " << b.getEnergyPoints() << std::endl;
	std::cout << c.getName() << " :" << std::endl 
				<< "hp = " << c.getHitPoints() << std::endl
				<< "ep = " << c.getEnergyPoints() << std::endl;
	std::cout << "X----------------X" << std::endl;
	b.beRepaired(2);
	c.beRepaired(15);
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
	b.attack(c.getName());
	c.takeDamage(b.getAttackDamage());
	c.attack(b.getName());
	b.takeDamage(c.getAttackDamage());
	c.setAttackDamage(15);
	c.attack(a.getName());
	a.takeDamage(c.getAttackDamage());
	std::cout << "X----------------X" << std::endl;
	std::cout << a.getName() << " :" << std::endl 
				<< "hp = " << a.getHitPoints() << std::endl
				<< "ep = " << a.getEnergyPoints() << std::endl;
	std::cout << b.getName() << " :" << std::endl 
				<< "hp = " << b.getHitPoints() << std::endl
				<< "ep = " << b.getEnergyPoints() << std::endl;
	std::cout << c.getName() << " :" << std::endl 
				<< "hp = " << c.getHitPoints() << std::endl
				<< "ep = " << c.getEnergyPoints() << std::endl;
	std::cout << "X----------------X" << std::endl;
	b.guardGate();
	c.highFivesGuys();
	std::cout << "X----------------X" << std::endl;
}