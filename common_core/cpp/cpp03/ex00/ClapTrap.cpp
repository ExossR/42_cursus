/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:16:30 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/26 11:30:29 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(""), _hit_p(0), _energy_p(0), _attack_dmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_p(10), _energy_p(10), _attack_dmg(0)
{
	std::cout << "Default constructor called (" << this->_name << ")" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called (" << this->_name << ")" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hit_p == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead. It can't attack." << std::endl;
		return ;
	}
	if (this->_energy_p > 0)
	{
		this->_energy_p--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target 
					<< ", causing " << this->_attack_dmg << " points of damage!"
					<< std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no energy points left." 
					<< " Can't attack." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_p == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead. It can't repaire." << std::endl;
		return ;
	}
	if (this->_energy_p > 0)
	{
		int	tmp;
		
		tmp = this->_hit_p;
		this->_energy_p--;
		if (this->_hit_p + amount > 10)
			this->_hit_p = 10;
		else
			this->_hit_p += amount;
		std::cout << "ClapTrap " << this->_name << " heals itself by " 
					<< (this->_hit_p + amount > 10 ? 10 - tmp : amount) 
					<< " points and now has " << this->_hit_p
					<< " hit points." << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no energy points left." 
					<< " Can't be repaired." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_p == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead bro :/" << std::endl;
		return ;
	}
	this->_hit_p -= amount;
	if (this->_hit_p <= 0)
	{
		this->_hit_p = 0;
		std::cout << "ClapTrap " << this->_name << " has been killed. Goodbye friend." 
					<< " It has been Destroyed." << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " took damage. It last him "
					<< this->_hit_p << " hit points." << std::endl;
}

std::string	ClapTrap::getName()
{
	return (this->_name);
}

int			ClapTrap::getAttackDamage()
{
	return (this->_attack_dmg);
}

void		ClapTrap::setAttackDamage(int a_dmg)
{
	this->_attack_dmg = a_dmg;
}

int			ClapTrap::getHitPoints()
{
	return (this->_hit_p);
}

int			ClapTrap::getEnergyPoints()
{
	return (this->_energy_p);
}
