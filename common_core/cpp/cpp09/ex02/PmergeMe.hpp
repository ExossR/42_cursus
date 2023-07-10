/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:50:47 by asahonet          #+#    #+#             */
/*   Updated: 2023/07/07 16:38:38 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <ctime>
#include <sstream>

class PmergeMe
{
	private:
		int					_size;
		std::vector<int>	_v;
		std::deque<int>		_d;

		PmergeMe();

		void    mergeVec(int begin, int middle, int end);
		void    vectorInsertionSort(int begin, int end);
		void    vectorMergeSort(int begin, int end);

		void    mergeDeque(int begin, int middle, int end);
		void    dequeInsertionSort(int begin, int end);
		void    dequeMergeSort(int begin, int end);
		
	public:
		PmergeMe(std::string s);
		PmergeMe(const PmergeMe& p);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& p);
		
		void	printVals();
		void	sortAll();
};