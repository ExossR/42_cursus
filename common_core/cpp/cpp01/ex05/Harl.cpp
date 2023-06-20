/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:36:05 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/11 11:34:32 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug()
{
	std::cout << "DEBUG" << std::endl;
}

void	Harl::info()
{
	std::cout << "INFO" << std::endl;
}

void	Harl::warning()
{
	std::cout << "WARNING" << std::endl;
}

void	Harl::error()
{
	std::cout << "ERROR" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	tab_str[4];
	fptr		tab_ptr[4];
	int			i = 0;

	tab_str[0] = "debug";
	tab_str[1] = "info";
	tab_str[2] = "warning";
	tab_str[3] = "error";

	tab_ptr[0] = &Harl::debug;
	tab_ptr[1] = &Harl::info;
	tab_ptr[2] = &Harl::warning;
	tab_ptr[3] = &Harl::error;
	
	while (i < 4)
	{
		if (level == tab_str[i])
		{
			(this->*tab_ptr[i])();
			return ;
		}
		i++;
	}
	std::cout << "Harl... Come on..." << std::endl;
}
