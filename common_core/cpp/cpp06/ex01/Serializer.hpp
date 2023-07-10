/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:43:03 by asahonet          #+#    #+#             */
/*   Updated: 2023/06/29 10:56:20 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

struct Data
{
	std::string	name;
	int			age;
};

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer& s);
		~Serializer();
		Serializer&	operator=(const Serializer& s);
		
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};