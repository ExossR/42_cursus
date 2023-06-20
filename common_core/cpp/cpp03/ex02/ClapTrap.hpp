/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:16:25 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/25 15:15:32 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_max_hp;
	protected:
		int			_hit_p;
		int			_energy_p;
		int			_attack_dmg;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, int maxhp, int hp, int ep, int att);
		~ClapTrap();
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName();
		int			getAttackDamage();
		void		setAttackDamage(unsigned int a_dmg);
		int			getHitPoints();
		void		setHitPoints(unsigned int a_hp);
		int			getEnergyPoints();
		void		setEnergyPoints(unsigned int a_ep);
		void		setMaxHP(int hp);
};