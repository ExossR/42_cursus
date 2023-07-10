/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:51:32 by asahonet          #+#    #+#             */
/*   Updated: 2023/06/29 12:37:05 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <iostream>
#include <unistd.h>

Base*	generate()
{
	int res;

	res = time(0) % 3;

	if (res == 0)
		return (new A());
	else if (res == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "ptr A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "ptr B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "ptr C." << std::endl;
	else
		std::cerr << "Error ptr." << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "ref A." << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "ref B." << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				std::cout << "ref C." << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error ref." << std::endl;
			}
		}
	}
}

int	main()
{
	Base* a = generate();
	
	identify(a);
	identify(*a);
	usleep(1000000);

	std::cout << std::endl;
	
	Base* b = generate();
	
	identify(b);
	identify(*b);
	usleep(1000000);
	
	std::cout << std::endl;
	
	Base* c = generate();

	identify(c);
	identify(*c);
}