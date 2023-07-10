/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:21:14 by asahonet          #+#    #+#             */
/*   Updated: 2023/06/29 11:35:43 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Serializer se = Serializer();
	Data*		d;
	uintptr_t	p;

	d->age = 5;
	d->name = "Tac";

	std::cout << "Data vals ; age :" << d->age << "; name :" << d->name << std::endl;
	p = se.serialize(d);
	std::cout << "p val ; p :" << p << std::endl;
	d = se.deserialize(p);
	std::cout << "Data vals ; age :" << d->age << "; name :" << d->name << std::endl;

}