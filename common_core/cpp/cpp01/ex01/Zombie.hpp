/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:21:21 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/03 13:28:59 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
	private :
		std::string	_name;
	public :
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	set_name(std::string name);
		void	announce();
};