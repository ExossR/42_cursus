/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:58:27 by lfresnay          #+#    #+#             */
/*   Updated: 2022/09/25 22:15:13 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tower.h"

int	check_line(int line[4], t_valeur coeff, int id)
{
	int	i;
	int	coeff_line;
	int	compteur;
	int	max;

	coeff_line = coeff.left[id];
	i = 0;
	compteur = 0;
	max = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			compteur += 1;
			max = line[i];
		}
		i++;
	}
	return (compteur == coeff_line);
}

int	check_column(int column[4][4], t_valeur coeff, int id)
{
	int	i;
	int	compteur;
	int	max;
	int	j;

	i = 0;
	compteur = 0;
	max = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (column[i][id] == column[j++][id])
				return (0);
		}
		if (column[i][id] > max)
		{
			compteur += 1;
			max = column[i][id];
		}
		i++;
	}
	return (compteur == coeff.up[id]);
}

int	check_reverse_line(int line[4], t_valeur coeff, int id)
{
	int	i;
	int	coeff_line;
	int	compteur;
	int	max;

	coeff_line = coeff.right[id];
	i = 3;
	compteur = 0;
	max = 0;
	while (i > -1)
	{
		if (line[i] > max)
		{
			compteur += 1;
			max = line[i];
		}
		i--;
	}
	return (compteur == coeff_line);
}

int	check_reverse_column(int column[4][4], t_valeur coeff, int id)
{
	int	i;
	int	coeff_column;
	int	compteur;
	int	max;

	coeff_column = coeff.down[id];
	i = 3;
	compteur = 0;
	max = 0;
	while (i > -1)
	{
		if (column[i][id] > max)
		{
			compteur += 1;
			max = column[i][id];
		}
		i--;
	}
	return (compteur == coeff_column);
}
