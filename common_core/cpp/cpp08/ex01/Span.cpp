/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:05:42 by asahonet          #+#    #+#             */
/*   Updated: 2023/07/03 13:16:03 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _maximum_integers(0)
{
}

Span::Span(unsigned int max_int): _maximum_integers(max_int)
{
}

Span::Span(const Span& s)
{
	this->_maximum_integers = s._maximum_integers;
	this->_arr = s._arr;
}

Span::~Span()
{
}

Span&	Span::operator=(const Span& s)
{
	if (this != &s)
	{
		this->_maximum_integers = s._maximum_integers;
		this->_arr = s._arr;
	}
	return (*this);
}

void	Span::addNumber(int x)
{
	if (this->_arr.size() == this->_maximum_integers)
		throw std::overflow_error("Maximum capacity reached.");
	this->_arr.push_back(x);
}

int		Span::shortestSpan()
{
	if (this->_arr.size() < 2)
		throw std::logic_error("Not enough numbers in the Span");
	int	span = (*std::max_element(this->_arr.begin(), this->_arr.end())) - *std::min_element(this->_arr.begin(), this->_arr.end());
	int	tmp;

	for (unsigned int j = 0; j < this->_arr.size(); j++)
	{
		tmp = this->_arr[j];
		for (unsigned int i = 0; i < this->_arr.size(); i++)
			if (this->_arr[i] - this->_arr[j] > 0 && this->_arr[i] - this->_arr[j] < span)
				span = this->_arr[i] - this->_arr[j];
		
	}
	return (span);
}

int		Span::longestSpan()
{
	if (this->_arr.size() < 2)
		throw std::logic_error("Not enough numbers in the Span");
	int min = *std::min_element(this->_arr.begin(), this->_arr.end());
    int max = *std::max_element(this->_arr.begin(), this->_arr.end());

	return (max - min);
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin; it != end; it++)
		addNumber(*it);
}