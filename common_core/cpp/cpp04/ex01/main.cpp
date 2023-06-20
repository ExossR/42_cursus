/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:39:20 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/27 17:49:35 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

/*void	test()
{
	{
		Animal	*a_arr[10];
		int		i = 0;
		
		while (i < 10)
		{
			if (i < 5)
				a_arr[i] = new Dog();
			else
				a_arr[i] = new Cat();
			i++;
		}
		std::cout << std::endl << "------------------------" << std::endl << std::endl;
		i = 0;
		while (i < 10)
		{
			a_arr[i]->makeSound();
			i++;
		}
		std::cout << std::endl << "------------------------" << std::endl << std::endl;
		i = 0;
		while (i < 10)
		{
			delete a_arr[i];
			i++;
		}
	}
}*/

int	main()
{
	//test();
	{
		Animal	*a_arr[10];
		int		i = 0;
		
		while (i < 10)
		{
			if (i < 5)
				a_arr[i] = new Dog();
			else
				a_arr[i] = new Cat();
			i++;
		}
		std::cout << std::endl << "------------------------" << std::endl << std::endl;
		i = 0;
		while (i < 10)
		{
			a_arr[i]->makeSound();
			i++;
		}
		std::cout << std::endl << "------------------------" << std::endl << std::endl;
		i = 0;
		while (i < 10)
		{
			delete a_arr[i];
			i++;
		}
	}
	//system("leaks animal");
}