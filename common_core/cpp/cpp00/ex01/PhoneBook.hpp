/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:50:21 by asahonet          #+#    #+#             */
/*   Updated: 2023/03/30 17:47:19 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
	private:
		Contact	_tab_c[8];
	public:
		PhoneBook();
		~PhoneBook();
		Contact	get_tab(int i);
		void	add_contact(std::string fn, std::string ln, std::string nn,
			std::string pn, std::string ds);
		void	search_contact(int index);
};
