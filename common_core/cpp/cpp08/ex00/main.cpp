/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:26:03 by asahonet          #+#    #+#             */
/*   Updated: 2023/06/30 13:37:12 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int	main()
{
	try
	{
		std::vector<int>	list_int;

		list_int.push_back(1);
		list_int.push_back(-1);
		list_int.push_back(9);
		list_int.push_back(3);
		list_int.push_back(4);		
		list_int.push_back(8);
		list_int.push_back(5);
		list_int.push_back(2);

		std::cout << "idx :" << (easyfind(list_int, 5) - list_int.begin()) << std::endl;
		std::cout << "idx :" << (easyfind(list_int, 7) - list_int.begin()) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}