/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:07:33 by asahonet          #+#    #+#             */
/*   Updated: 2023/06/30 12:27:36 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
	try
	{
		Array<int>	tab1 = Array<int>();
		
		std::cout << "Size tab1 :" << tab1.size() << std::endl;

		std::cout << "-----------------------" << std::endl;

		Array<int>	tab2 = Array<int>(5);

		tab2[0] = 1;
		tab2[1] = 2;
		tab2[2] = 3;
		tab2[3] = 4;
		tab2[4] = 5;

		std::cout << "Size tab2 :" << tab2.size() << std::endl;

		for (unsigned int i = 0; i < tab2.size(); i++)
			std::cout << "tab2[" << i << "] = " << tab2[i] << std::endl;

		std::cout << "-----------------------" << std::endl;

		Array<int> cpyTab = tab2;
		
		for (unsigned int i = 0; i < cpyTab.size(); i++)
			std::cout << "cpyTab[" << i << "] = " << cpyTab[i] << std::endl;
		
		std::cout << "-----------------------" << std::endl;

		tab2[0] = 42;

		for (unsigned int i = 0; i < tab2.size(); i++)
			std::cout << "tab2[" << i << "] = " << tab2[i] << std::endl;
		
		std::cout << "-----------------------" << std::endl;

		int	val = tab2[5];
		
		std::cout << "Val :" << val << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception :" << e.what() << std::endl;
	}
}