/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:21:34 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/03 13:28:50 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name): _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << this->_name << " have been killed. FATALITY." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
