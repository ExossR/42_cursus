/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:54:47 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/28 13:36:27 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AAnimal.hpp"

class Dog: public Animal
{
	private:
		Brain*	_brain;
	public:
		Dog();
		Dog(std::string type);
		Dog(Dog const &d);
		~Dog();
		Dog&	operator=(Dog const &d);
		void	makeSound();
};