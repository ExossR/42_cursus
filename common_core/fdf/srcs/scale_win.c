/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:54:14 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/29 15:01:35 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	value_of_z(int max)
{
	int	res;

	if (max == 0)
		return (10);
	res = (O_Y + 35) / max;
	if (res == 0)
		return (1);
	return (res);
}

int	val_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	max_val_z(t_point **map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].x != -1)
		{
			if (val_abs(map[i][j].z) > max)
				max = val_abs(map[i][j].z);
			j++;
		}
		i++;
	}
	return (max);
}

int	segment_size(t_point **map)
{
	int	n;

	n = sqrt((M_X - O_X) * (M_X - O_X) + (M_Y - O_Y) * (M_Y - O_Y));
	n /= max(count_x(map), count_y(map));
	return (n);
}

void	convert_map(t_point **map)
{
	int	i;
	int	j;
	int	seg_s;
	int	z_val;

	z_val = value_of_z(max_val_z(map));
	seg_s = segment_size(map);
	set_coordonate(&map[0][0], O_X, O_Y, map[0][0].z);
	i = -1;
	while (map[++i] != 0)
	{
		j = 0;
		if (i != 0)
			set_coordonate(&map[i][0],
				O_X - 0.866 * (seg_s * i),
				O_Y + (map[0][0].z * z_val) + 0.5 * (seg_s * i)
				- (map[i][0].z * z_val), map[i][0].z);
		while (map[i][++j].x != -1)
		{
			set_coordonate(&map[i][j],
				map[i][0].x + 0.866 * (seg_s * j),
				map[i][0].y + (map[i][0].z * z_val) + 0.5 * (seg_s * j)
				- (map[i][j].z * z_val), map[i][j].z);
		}
	}
}
