/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:34:56 by asahonet          #+#    #+#             */
/*   Updated: 2023/06/28 13:49:15 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& sc)
{
	*this = sc;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& sc)
{
	*this = sc;
	return (*this);
}

void	ScalarConverter::convert(std::string str)
{
	std::string otherVals[6];
	bool		isOther = false;
	std::string	toChar = "'";
	int			toInt = 0;
	double		toDouble = 0;
	float		toFloat = 0;
	
	otherVals[0] = "-inf";
	otherVals[1] = "+inf";
	otherVals[2] = "nan";
	otherVals[3] = "-inff";
	otherVals[4] = "+inff";
	otherVals[5] = "nanf";
	
	for (int i = 0; i < 6; i++)
		if (str == otherVals[i])
			isOther = true;

	if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
	{
		std::cout << "char	: '" << str[0] << "'" << std::endl;
		std::cout << "int	: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float	: " << static_cast<float>(str[0]) << ".0f" << std::endl;
		std::cout << "double	: " << static_cast<double>(str[0]) << ".0" << std::endl;
		return ;
	}
	toInt = std::atoi(str.c_str());
	
	if (str[str.size() - 1] == 'f')
	{
		toFloat = std::atof(str.c_str());
		toDouble = static_cast<double>(toFloat);
	}
	else
	{
		toDouble = std::atof(str.c_str());
		toFloat = static_cast<float>(toDouble);
	}
	
	if (!(toInt > 31 && toInt < 128 && !isOther))
		toChar = "impossible";
	else
	{
		toChar += static_cast<char>(toInt);
		toChar += "'";
	}
	
	std::cout << "char	: " << toChar << std::endl;
	std::cout << "int	: ";
	if (isOther)
		std::cout << "impossible" << std::endl;
	else
		std::cout << toInt << std::endl;
	std::cout << "float	: " << toFloat << (toInt == toFloat ? ".0f" : "f") << std::endl;
	std::cout << "double	: " << toDouble << (toInt == toDouble ? ".0" : "") << std::endl;
}