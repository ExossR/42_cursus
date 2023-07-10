/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:42:32 by asahonet          #+#    #+#             */
/*   Updated: 2023/06/30 13:33:11 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

template<typename T>
typename T::iterator	easyfind(T& container, int val)
{
	typename T::iterator it = container.begin();
	typename T::iterator end = container.end();

	while (it != end)
	{
		if (*it == val)
			return (it);
		it++;
	}
	throw std::exception();
}