/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:08:35 by asahonet          #+#    #+#             */
/*   Updated: 2023/07/07 15:46:13 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Usage: ./PmergeMe <parameters>" << std::endl;
		return (1);
	}

	std::string	args = "";
	int			i = 1;

	while (argv[i])
	{
		args += argv[i];
		args += " ";
		i++;
	}
	
	try
	{
		PmergeMe mergesort(args);
		
		mergesort.printVals();
		mergesort.sortAll();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}