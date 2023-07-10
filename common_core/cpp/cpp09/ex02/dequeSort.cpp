/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeSort.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:16:29 by asahonet          #+#    #+#             */
/*   Updated: 2023/07/07 16:20:16 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    PmergeMe::mergeDeque(int begin, int middle, int end)
{
	int	deq1 = middle - begin + 1;
	int	deq2 = end - middle;

	std::deque<int>	leftDeq(deq1);
	std::deque<int>	rightDeq(deq2);

	for (int i = 0; i < deq1; i++)
		leftDeq[i] = this->_d[begin + i];
	for (int i = 0; i < deq2; i++)
		rightDeq[i] = this->_d[middle + 1 + i];

	int	right = 0;
	int	left = 0;

	for (int i = begin; i <= end; i++)
	{
		if (right == deq2)
		{
			this->_d[i] = leftDeq[left];
			left++;
		}
		else if (left == deq1)
		{
			this->_d[i] = rightDeq[right];
			right++;
		}
		else if (rightDeq[right] > leftDeq[left])
		{
			this->_d[i] = leftDeq[left];
			left++;
		}
		else
		{
			this->_d[i] = rightDeq[right];
			right++;
		}
	}
}

void    PmergeMe::dequeInsertionSort(int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		int temp = this->_d[i + 1];
		int index = i + 1;

		while (index > begin && this->_d[index - 1] > temp)
		{
			this->_d[index] = this->_d[index - 1];
			index--;
		}
		this->_d[index] = temp;
	}
}

void    PmergeMe::dequeMergeSort(int begin, int end)
{
	int	changeSort = 5;

	if (end - begin > changeSort)
	{
		int	middleIndex = (begin + end) / 2;
		dequeMergeSort(begin, middleIndex);
		dequeMergeSort(middleIndex + 1, end);

		mergeDeque(begin, middleIndex, end);
	}
	else
		dequeInsertionSort(begin, end);
}