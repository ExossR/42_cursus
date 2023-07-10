/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:26:20 by asahonet          #+#    #+#             */
/*   Updated: 2023/07/04 10:46:47 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <iterator>

template<typename T>
class MutantStack: public std::stack<T, std::deque<T> >
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
	
		MutantStack()
		{
		}
		
		MutantStack(const MutantStack& m)
		{
			this = &m;
		}
		
		~MutantStack()
		{
		}
		
		MutantStack& operator=(const MutantStack& m)
		{
			this = &m;
			return (*this);
		}
		
		iterator	begin()
		{
			return (this->c.begin());
		}

		iterator	end()
		{
			return (this->c.end());
		}
};