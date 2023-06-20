/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:16:25 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/26 11:29:09 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hit_p;
		int			_energy_p;
		int			_attack_dmg;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName();
		int			getAttackDamage();
		void		setAttackDamage(int	a_dmg);
		int			getHitPoints();
		int			getEnergyPoints();
};