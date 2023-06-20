/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:18:36 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/05 15:31:10 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	this->_weapon = 0;
	std::cout << "HumanB " << this->_name << " has been created without weapon!" << std::endl;
}

HumanB::HumanB(std::string name, Weapon *weapon): _name(name), _weapon(weapon)
{
	std::cout << "HumanB " << this->_name << " has been created with weapon!" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB has been destroyed." << std::endl;
}

void	HumanB::setWeapon(Weapon *weapon)
{
	this->_weapon = weapon;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}