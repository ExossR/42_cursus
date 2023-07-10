/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:15:00 by asahonet          #+#    #+#             */
/*   Updated: 2023/06/29 10:40:31 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cctype>
#include <string>
#include <iostream>
#include <sstream> 

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& sc);
		~ScalarConverter();
		ScalarConverter&	operator=(const ScalarConverter& sc);

		static void	convert(std::string str);
};