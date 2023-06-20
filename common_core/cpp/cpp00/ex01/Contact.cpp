/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:02:37 by asahonet          #+#    #+#             */
/*   Updated: 2023/03/30 11:23:43 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(): _firstname(""), _lastname(""), _nickname(""), _phone_number(""), _darkest_secret("")
{
}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds):
					_firstname(fn), _lastname(ln), _nickname(nn), _phone_number(pn), _darkest_secret(ds)
{
}

Contact::~Contact()
{
}

std::string	Contact::get_fn()
{
	return (this->_firstname);
}

std::string	Contact::get_ln()
{
	return (this->_lastname);
}

std::string	Contact::get_nn()
{
	return (this->_nickname);
}

std::string	Contact::get_pn()
{
	return (this->_phone_number);
}

std::string	Contact::get_ds()
{
	return (this->_darkest_secret);
}
