/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:07:00 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/27 18:11:19 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	j;
	int	*arr;

	if (min >= max)
		return (0);
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

/*#include <stdio.h>

int	main(void)
{
	int	*tab = ft_range(10, 15);
	int i;
	
	i = 0;
	while (tab[i])
	{
		printf("%d\n", tab[i]);
		i++;
	}
}*/
