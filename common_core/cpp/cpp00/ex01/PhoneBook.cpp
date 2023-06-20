/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:56:06 by asahonet          #+#    #+#             */
/*   Updated: 2023/03/30 19:43:59 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{	
}

PhoneBook::~PhoneBook()
{
}

Contact	PhoneBook::get_tab(int i)
{
	return (this->_tab_c[i]);
}

void	PhoneBook::add_contact(std::string fn, std::string ln, std::string nn,
								std::string pn, std::string ds)
{
	Contact	c(fn, ln, nn, pn, ds);
	for (int i = 6; i >= 0; i--)
		this->_tab_c[i + 1] = this->_tab_c[i];
	this->_tab_c[0] = c;
}

void	PhoneBook::search_contact(int index)
{
	if (index > 7 || index < 0)
	{
		std::cout << "L'index choisi est errone, veuillez reessayer avec un index correcte."
			<< std::endl;
		return ;
	}
	if (this->_tab_c[index].get_fn().empty())
	{
		std::cout << "Il n'y a pas de contact a cet index, veuillez ressayer avec un index correcte."
			<< std::endl;
		return ;
	}
	std::cout << this->_tab_c[index].get_fn() << std::endl;
	std::cout << this->_tab_c[index].get_ln() << std::endl;
	std::cout << this->_tab_c[index].get_nn() << std::endl;
	std::cout << this->_tab_c[index].get_pn() << std::endl;
	std::cout << this->_tab_c[index].get_ds() << std::endl;
}