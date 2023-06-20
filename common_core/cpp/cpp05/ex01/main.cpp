/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:07:05 by asahonet          #+#    #+#             */
/*   Updated: 2023/05/02 16:50:30 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat b = Bureaucrat("Palmi", 150);
		std::cout << b << std::endl;
		b.decrGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	Bureaucrat *b1 = new Bureaucrat("Jean", 1);
	try
	{
		std::cout << *b1 << std::endl;
		b1->incrGrade();
		std::cout << *b1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete b1;
	
	std::cout << std::endl;
	
	try
	{
		Bureaucrat b2 = Bureaucrat("Pierre", 15);
		std::cout << b2 << std::endl;
		b2.incrGrade();
		std::cout << b2 << std::endl;
		b2.incrGrade();
		std::cout << b2 << std::endl;
		for (int i = 0; i < 10; i++)
			b2.decrGrade();
		std::cout << b2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Bureaucrat b3 = Bureaucrat("Yoshi", -1);
		std::cout << b3 << std::endl;
		b3.incrGrade();
		std::cout << b3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}