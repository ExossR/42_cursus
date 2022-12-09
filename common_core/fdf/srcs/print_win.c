/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:07:14 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/07 19:36:15 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_data *mlx, t_point a, t_point b)
{
	double	delta_x;
	double	delta_y;
	double	pxl_x;
	double	pxl_y;
	int		pxl;

	delta_x = b.x - a.x;
	delta_y = b.y - a.y;
	pxl = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pxl;
	delta_y /= pxl;
	pxl_x = a.x;
	pxl_y = a.y;
	while (pxl > 0)
	{
		if (pxl_y > 0 && pxl_y < W_HEIGHT && pxl_x > 0 && pxl_x < W_WIDTH)
			my_mlx_pixel_put(mlx, pxl_x, pxl_y, 0x00FFFFFF);
		pxl_x += delta_x;
		pxl_y += delta_y;
		pxl--;
	}
}

void	print_all_lines(t_point **map, t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].x != -1)
		{
			if (map[i][j + 1].x != -1)
				draw_line(mlx, map[i][j], map[i][j + 1]);
			if (map[i + 1])
				draw_line(mlx, map[i][j], map[i + 1][j]);
			j++;
		}
		i++;
	}
}
