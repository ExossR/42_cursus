/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:38:24 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/12 14:35:59 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_square_blank(t_game *g, t_image *img)
{
	int	x;
	int	y;
	int	endx;
	int	endy;

	x = 0;
	y = 0;
	endx = MMAP_RES * (g->map_s.x + 1);
	endy = MMAP_RES * (g->map_s.y + 1);
	while (y <= endy && x <= endx)
	{
		while (x <= endx)
		{
			my_mlx_pixel_put(img, x, y, 0xFF000000);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_square_play(int x, int y, int color, t_image *img)
{
	int	endx;
	int	endy;

	endx = x + (MMAP_RES / 4);
	endy = y + (MMAP_RES / 4);
	while (y <= endy)
	{
		if (x >= endx)
		{
			x -= (MMAP_RES / 4);
			y++;
		}
		if (y <= endy)
			my_mlx_pixel_put(img, x, y, color);
		x++;
	}
}

void	ft_square(int x, int y, int color, t_image *img)
{
	int	endx;
	int	endy;

	endx = x + MMAP_RES;
	endy = y + MMAP_RES;
	while (y <= endy)
	{
		if (x >= endx)
		{
			x -= MMAP_RES;
			y++;
		}
		if (y <= endy)
			my_mlx_pixel_put(img, x, y, color);
		x++;
	}
}
