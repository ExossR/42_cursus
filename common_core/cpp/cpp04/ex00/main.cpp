/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:39:20 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/27 17:16:30 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
	}
	std::cout << std::endl << "------------------------" << std::endl << std::endl;
	{
		Dog dog = Dog("Oui");
		Cat cat = Cat("Non");

		dog.makeSound();
		cat.makeSound();
	}
	std::cout << std::endl << "------------------------" << std::endl << std::endl;
	{
		Dog 		dogg;
		Cat 		catt;
		Dog const	dogi("Labrador");
		
		dogg = dogi;
		
		dogg.makeSound();
		catt.makeSound();
	}
}