/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:43:33 by asahonet          #+#    #+#             */
/*   Updated: 2023/06/30 12:19:32 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

template<typename T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size_array;
	
	public:
		Array(): _array(0), _size_array(0)
		{
		}
		
		Array(unsigned int n): _array(new T[n]), _size_array(n)
		{
			for (unsigned int i = 0; i < this->_size_array; i++)
				this->_array[i] = T();
		}
		
		Array(const Array& a)
		{
			this->_array = new T[a._size_array];
			this->_size_array = a._size_array;
			for (unsigned int i = 0; i < this->_size_array; i++)
				this->_array[i] = a._array[i];
		}
		
		~Array()
		{
			delete[] this->_array;
		}
		
		Array&	operator=(const Array& a)
		{
			if (*this != a)
			{
				T*	newArray = new T[a._size_array];
				this->_size_array = a._size_array;
				for (unsigned int i = 0; i < a._size_array; i++)
					newArray[i] = a._array[i];

				delete[] this->_array;
				this->_array = newArray;
			}
			return (*this);
		}
		
		T&		operator[](unsigned int idx)
		{
			if (idx >= this->_size_array)
				throw std::exception();
			return (this->_array[idx]);
		}

		unsigned int	size() const
		{
			return (this->_size_array);
		}
};