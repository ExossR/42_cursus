/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:31:57 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/04 11:39:05 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "Memory address simple: " << &brain << std::endl;
	std::cout << "Memory address    PTR: " << stringPTR << std::endl;
	std::cout << "Memory address    REF: " << &stringREF << std::endl;

	std::cout << "-------------------------" << std::endl;

	std::cout << "Value simple: " << brain << std::endl;
	std::cout << "Value    PTR: " << *stringPTR << std::endl;
	std::cout << "Value    REF: " << stringREF << std::endl;
}