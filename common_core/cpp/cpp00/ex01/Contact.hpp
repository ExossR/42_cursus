/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:50:31 by asahonet          #+#    #+#             */
/*   Updated: 2023/03/30 10:02:54 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Contact
{
	private :
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
	
	public :
		Contact();
		Contact(std::string fn, std::string ln, std::string nn,
			std::string pn, std::string ds);
		~Contact();
		std::string	get_fn();
		std::string	get_ln();
		std::string	get_nn();
		std::string	get_pn();
		std::string	get_ds();
};
