/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:16:30 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/26 11:30:47 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(""), _max_hp(0), _hit_p(0), _energy_p(0), _attack_dmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _max_hp(10), _hit_p(10), _energy_p(10), _attack_dmg(0)
{
	std::cout << "Default constructor called (" << this->_name << ")" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int maxhp, int hp, int ep, int att): _name(name), _max_hp(maxhp), _hit_p(hp), _energy_p(ep), _attack_dmg(att)
{
	std::cout << "Constructor Claptrap called (" << this->_name << ")" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called (" << this->_name << ")" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hit_p == 0)
	{
		std::cout << this->_name << " is dead. It can't attack." << std::endl;
		return ;
	}
	if (this->_energy_p > 0)
	{
		this->_energy_p--;
		std::cout << this->_name << " attacks " << target 
					<< ", causing " << this->_attack_dmg << " points of damage!"
					<< std::endl;
	}
	else
		std::cout << this->_name << " has no energy points left." 
					<< " Can't attack." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_p == 0)
	{
		std::cout << this->_name << " is dead. It can't repaire." << std::endl;
		return ;
	}
	if (this->_energy_p > 0)
	{
		int	tmp;
		
		tmp = this->_hit_p;
		this->_energy_p--;
		if (this->_hit_p + (int)amount > this->_max_hp)
			this->_hit_p = this->_max_hp;
		else
			this->_hit_p += amount;
		std::cout << this->_name << " heals itself by " 
					<< (this->_hit_p + (int)amount > this->_max_hp ? this->_hit_p - tmp : amount) 
					<< " points and now has " << this->_hit_p
					<< " hit points." << std::endl;
	}
	else
		std::cout << this->_name << " has no energy points left." 
					<< " Can't be repaired." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_p == 0)
	{
		std::cout << this->_name << " is already dead bro :/" << std::endl;
		return ;
	}
	this->_hit_p -= amount;
	if (this->_hit_p <= 0)
	{
		this->_hit_p = 0;
		std::cout << this->_name << " has been killed. Goodbye friend." 
					<< " It has been Destroyed." << std::endl;
	}
	else
		std::cout << this->_name << " took damage. It last him "
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

void		ClapTrap::setAttackDamage(unsigned int a_dmg)
{
	this->_attack_dmg = a_dmg;
}

int			ClapTrap::getHitPoints()
{
	return (this->_hit_p);
}

void		ClapTrap::setHitPoints(unsigned int a_hp)
{
	this->_hit_p = a_hp;
}

int			ClapTrap::getEnergyPoints()
{
	return (this->_energy_p);
}

void		ClapTrap::setEnergyPoints(unsigned int a_ep)
{
	this->_energy_p = a_ep;
}

void		ClapTrap::setMaxHP(int hp)
{
	this->_max_hp = hp;
}