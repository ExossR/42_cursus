/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tower.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:56:54 by keschouf          #+#    #+#             */
/*   Updated: 2022/09/25 17:04:08 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tower.h"

void	print_map(int map[4][4])
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (j <= 3)
	{
		i = 0;
		while (i <= 3)
		{
			c = '0' + map[j][i];
			write(1, &c, 1);
			if (i < 3)
				write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int	is_map_valid(int map[4][4], t_valeur coeff)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_column(map, coeff, i)
			|| !check_reverse_column(map, coeff, i))
			return (0);
		i++;
	}
	return (1);
}

int	back_tracking(int ***valid, int depth, int map[4][4], t_valeur coeff)
{
	int	i;
	int	j;

	i = 0;
	while (valid[depth][i])
	{
		j = -1;
		while (++j < 4)
			map[depth][j] = valid[depth][i][j];
		if (depth < 3)
		{
			if (back_tracking(valid, depth + 1, map, coeff))
				return (1);
		}
		else
		{
			if (is_map_valid(map, coeff))
			{
				print_map(map);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	solve_map(int ***valid, t_valeur coeff)
{
	int	map[4][4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			map[i][j] = valid[i][0][j];
			j++;
		}
		i++;
	}
	if (back_tracking(valid, 0, map, coeff) == 0)
		write(1, "Error\n", 6);
}
