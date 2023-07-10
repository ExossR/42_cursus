/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:19:17 by asahonet          #+#    #+#             */
/*   Updated: 2023/07/05 13:31:07 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage: ./btc <input_file>" << std::endl;
		return (1);
	}

	BitcoinExchange btc = BitcoinExchange();
	
	std::map<std::string, double>	map = btc.getMapDateVal();
	if (map.size() == 0)
		return (1);
	
	std::map<std::string, double>::iterator	it = map.begin();
	std::map<std::string, double>::iterator	ite = map.end();

	// while (it != ite)
	// {
	// 	std::cout << "date :" << it->first << " ; val :" << it->second << std::endl;
	// 	it++;
	// }
	try
	{
		btc.printResults(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}