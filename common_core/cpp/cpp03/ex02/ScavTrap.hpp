/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:57:00 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/25 15:12:02 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		std::string	_name;
		int			_hit_p;
		int			_energy_p;
		int			_attack_dmg;
		int			_max_hp;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		void		attack(const std::string& target);
		void		guardGate();
};