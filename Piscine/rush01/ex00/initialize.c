/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:55:36 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/25 16:26:21 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tower.h"

int	nb_working(int tab[24][4], int id, t_valeur coeff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 24)
	{
		if (check_line(tab[i], coeff, id)
			&& check_reverse_line(tab[i], coeff, id))
			j++;
		i++;
	}
	return (j);
}

int	**get_working(int tab[24][4], int id, int **valid, t_valeur coeff)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	while (i < 24)
	{
		if (check_line(tab[i], coeff, id)
			&& check_reverse_line(tab[i], coeff, id))
		{
			k = 0;
			valid[j] = (int *)malloc(4 * sizeof(int));
			while (k < 4)
			{
				valid[j][k] = tab[i][k];
				k++;
			}
			j++;
		}
		i++;
	}
	valid[j] = 0;
	return (valid);
}

int	***initialize(int all[4][24][4], int ***valid, t_valeur coeff)
{
	int	i;

	valid = (int ***)malloc(4 * sizeof(int **));
	i = 0;
	while (i < 4)
	{
		if (nb_working(all[i], i, coeff) == 0)
			return (0);
		valid[i] = malloc((nb_working(all[i], i, coeff) + 1) * sizeof(int *));
		valid[i] = get_working(all[i], i, valid[i], coeff);
		i++;
	}
	return (valid);
}
