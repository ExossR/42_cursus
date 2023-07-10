/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorSort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:30:24 by asahonet          #+#    #+#             */
/*   Updated: 2023/07/07 14:51:14 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    PmergeMe::mergeVec(int begin, int middle, int end)
{
	int	vec1 = middle - begin + 1;
	int	vec2 = end - middle;

	std::vector<int>	leftVec(vec1);
	std::vector<int>	rightVec(vec2);

	for (int i = 0; i < vec1; i++)
		leftVec[i] = this->_v[begin + i];
	for (int i = 0; i < vec2; i++)
		rightVec[i] = this->_v[middle + 1 + i];

	int	right = 0;
	int	left = 0;

	for (int i = begin; i <= end; i++)
	{
		if (right == vec2)
		{
			this->_v[i] = leftVec[left];
			left++;
		}
		else if (left == vec1)
		{
			this->_v[i] = rightVec[right];
			right++;
		}
		else if (rightVec[right] > leftVec[left])
		{
			this->_v[i] = leftVec[left];
			left++;
		}
		else
		{
			this->_v[i] = rightVec[right];
			right++;
		}
	}
}

void    PmergeMe::vectorInsertionSort(int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		int temp = this->_v[i + 1];
		int index = i + 1;

		while (index > begin && this->_v[index - 1] > temp)
		{
			this->_v[index] = this->_v[index - 1];
			index--;
		}
		this->_v[index] = temp;
	}
}

void    PmergeMe::vectorMergeSort(int begin, int end)
{
	int	changeSort = 5;

	if (end - begin > changeSort)
	{
		int	middleIndex = (begin + end) / 2;
		vectorMergeSort(begin, middleIndex);
		vectorMergeSort(middleIndex + 1, end);

		mergeVec(begin, middleIndex, end);
	}
	else
		vectorInsertionSort(begin, end);
}