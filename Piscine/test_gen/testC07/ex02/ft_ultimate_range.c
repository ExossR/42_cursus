/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:19:44 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/27 18:44:44 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	j;
	int	*arr;

	i = min;
	j = 0;
	arr = malloc((max - min) * sizeof(int));
	while (i < max)
	{
		arr[j] = i;
		i++;
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	diff;

	diff = max - min;
	if (min >= max || (min < 0 || max < 0))
	{
		*range = 0;
		return (0);
	}
	if (range == 0)
		return (-1);
	range[0] = ft_range(min, max);
	range[1] = 0;
	return (diff);
}

/*#include <stdio.h>

int	main(void)
{
	int *range;
	int	j;
	int	res;
	int min = 15;
	int max = 21;

	j = 0;
	res = ft_ultimate_range(&range, min, max);
	if (res == 0 || res == -1)
	{
		printf("Erreur dans ft_range : %d", res);
		return (0);
	}
	//printf("%d\n", res);
	while (j < res)
	{
		printf("%d\n", range[j]);
		j++;
	}
	return (0);
}*/
