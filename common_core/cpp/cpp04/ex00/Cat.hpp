/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:05:47 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/27 17:25:41 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(std::string type);
		Cat(Cat const &c);
		~Cat();
		Cat&	operator=(Cat const &c);
		void	makeSound() const;
};