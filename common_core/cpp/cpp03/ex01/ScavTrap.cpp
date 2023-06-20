/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:56:50 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/25 15:40:11 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("", 100, 100, 50, 20), _name(""), _hit_p(100), _energy_p(50), _attack_dmg(20), _max_hp(100)
{
	std::cout << "Default ScavTrap constructor called (" << this->_name << ")" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 100, 50, 20), _name(name), _hit_p(100), _energy_p(50), _attack_dmg(20), _max_hp(100)
{
	std::cout << "Default ScavTrap constructor called (" << this->_name << ")" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called (" << this->_name << ")" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	(void) this->_max_hp;
	if (this->_hit_p == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead. It can't attack." << std::endl;
		return ;
	}
	if (this->_energy_p > 0)
	{
		this->_energy_p--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target 
					<< ", causing " << this->_attack_dmg << " points of damage!"
					<< std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " has no energy points left." 
					<< " Can't attack." << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_hit_p == 0)
		std::cout << this->_name << " is now in Gate keeper mode. But he is dead :/" << std::endl;
	else
		std::cout << this->_name << " is now in Gate keeper mode." << std::endl;
}
