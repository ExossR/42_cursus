/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:38:32 by asahonet          #+#    #+#             */
/*   Updated: 2023/07/07 16:31:29 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _size(0), _v(), _d()
{
}

PmergeMe::PmergeMe(std::string s)
{
	std::stringstream	ss(s);
	std::string			tmp;
	int					val;
	
	while (ss >> tmp)
	{
		int	i = 0;
		while (tmp[i])
		{
			if (!((tmp[i] >= 48 && tmp[i] <= 57) 
				|| (tmp[i] == '-' && tmp[i + 1] != '\0' && tmp[i + 1] >= 48 && tmp[i + 1] <= 57)))
				throw std::invalid_argument("Error: non-number found");
			i++;
		}
		val = static_cast<int>(std::atoi(tmp.c_str()));
		if (val < 0)
			throw std::invalid_argument("Error: negative number");
		// if (std::find(this->_v.begin(), this->_v.end(), val) != this->_v.end())
		// 	throw std::invalid_argument("Error: duplicate number");
		this->_v.push_back(val);
		this->_d.push_back(val);
	}
	if (this->_v.size() > 3000)
		throw std::invalid_argument("Error: too many numbers, fix it please");
	this->_size = this->_v.size();
}

PmergeMe::PmergeMe(const PmergeMe& p)
{
	*this = p;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& p)
{
	if (this != &p)
	{
		this->_v = p._v;
		this->_d = p._d;
		this->_size = p._size;
	}
	return (*this);
}

void	PmergeMe::printVals()
{
	int							i = 0;
	std::vector<int>::iterator	it = this->_v.begin();
	std::vector<int>::iterator	ite = this->_v.end();

	std::cout << "Numbers : ";
	while (it != ite && i != 5)
	{
		std::cout << *it << " ";
		it++;
		i++;
	}
	std::cout << "[...]" << std::endl;
}

void	PmergeMe::sortAll()
{
	int	begin = 0;
	int	end = this->_size - 1;

	std::clock_t	start_v = std::clock();
	double			duration_v;

	vectorMergeSort(begin, end);
	
	duration_v = (std::clock() - start_v) / (double) 1000;

	std::clock_t	start_d = std::clock();
	double			duration_d;

	dequeMergeSort(begin, end);

	duration_d = (std::clock() - start_d) / (double) 1000;
	
	printVals();
	
	std::cout << "Time to process a range of " << this->_size << " with std::vector : " << duration_v << " ms" << std::endl;
	std::cout << "Time to process a range of " << this->_size << " with std::deque : " << duration_d << " ms" << std::endl;
}