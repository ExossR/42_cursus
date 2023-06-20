/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:49:53 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/05 15:34:07 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon *weapon): _name(name), _weapon(weapon)
{
	std::cout << "HumanA " << this->_name << " has been created!" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA has been destroyed." << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}