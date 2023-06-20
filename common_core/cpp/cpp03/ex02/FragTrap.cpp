/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:11:54 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/25 15:41:09 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("", 100, 100, 50, 20), _name(""), _hit_p(100), _energy_p(50), _attack_dmg(20), _max_hp(100)
{
	std::cout << "Default FragTrap constructor called (" << this->_name << ")" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 50, 20), _name(name), _hit_p(100), _energy_p(50), _attack_dmg(20), _max_hp(100)
{
	std::cout << "Default FragTrap constructor called (" << this->_name << ")" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap called (" << this->_name << ")" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	(void) _energy_p;
	(void) _attack_dmg;
	(void) _max_hp;
	if (this->_hit_p == 0)
		std::cout << this->_name << " wants to high five ! But he is dead bro, clap this skeleton lmao..." << std::endl; 
	else
		std::cout << this->_name << " wants to high five ! Let's do it !" << std::endl; 
}
