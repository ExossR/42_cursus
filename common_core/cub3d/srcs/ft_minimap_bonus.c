/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:48:39 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/19 17:48:37 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	ft_init_line_infos(t_game *g, int x1, int y1)
{
	g->line.x0 = (int)(g->play.dx * MMAP_RES);
	g->line.y0 = (int)(g->play.dy * MMAP_RES);
	g->line.dx = abs(x1 - g->line.x0);
	g->line.dy = abs(y1 - g->line.y0);
	if (g->line.x0 < x1)
		g->line.sx = 1;
	else
		g->line.sx = -1;
	if (g->line.y0 < y1)
		g->line.sy = 1;
	else
		g->line.sy = -1;
	g->line.err = g->line.dx - g->line.dy;
}

/* Display field of view on minimap */
static void	ft_draw_line(t_game *g, t_image *img, int x1, int y1)
{
	ft_init_line_infos(g, x1, y1);
	while (g->line.x0 != x1 || g->line.y0 != y1)
	{
		g->line.e2 = g->line.err * 2;
		if (g->line.e2 > -g->line.dy)
		{
			g->line.err -= g->line.dy;
			g->line.x0 += g->line.sx;
		}
		if (g->line.e2 < g->line.dx)
		{
			g->line.err += g->line.dx;
			g->line.y0 += g->line.sy;
		}
		if (g->map[g->line.y0 / MMAP_RES][g->line.x0 / MMAP_RES] != '0')
			break ;
		if (g->line.x0 > 0 && g->line.y0 > 0)
			my_mlx_pixel_put(img, g->line.x0, g->line.y0, MMAP_FVC);
	}
}

/* First while Camera Plan test field view on mmap, OK */
/* Second while Display direction in mmap*/
void	ft_draw_player(t_game *g, t_image *img)
{
	int	i;
	int	x;
	int	y;
	int	x2;
	int	y2;

	my_mlx_pixel_put(img, g->play.dx * MMAP_RES, g->play.dy
		* MMAP_RES, MMAP_PC);
	i = (MMAP_RES * FOV_ANGLE / 100) * -1 * (FOV_ANGLE * 2);
	x2 = (g->play.dx * MMAP_RES) + 250 * (g->v_dir.dx * MMAP_RES) / MMAP_RES;
	y2 = (g->play.dy * MMAP_RES) + 250 * (g->v_dir.dy * MMAP_RES) / MMAP_RES;
	while (i < MMAP_RES * FOV_ANGLE / 100 * (FOV_ANGLE * 2))
	{
		x = x2 + i * (g->v_plan.dx * MMAP_RES) / MMAP_RES;
		y = y2 + i * (g->v_plan.dy * MMAP_RES) / MMAP_RES;
		ft_draw_line(g, img, x, y);
		i++;
	}
}

void	ft_draw_minimap(t_game *g, t_image *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_square_blank(g, img);
	while (g->map[y])
	{
		while (g->map[y][x])
		{
			if (g->map[y][x] == '1')
			{
				ft_square(x * MMAP_RES, y * MMAP_RES, MMAP_WC, img);
				ft_square((x + 1) * MMAP_RES, (y + 1) * MMAP_RES, MMAP_SC, img);
			}
			else if (g->map[y][x] == '0')
				ft_square(x * MMAP_RES, y * MMAP_RES, MMAP_FC, img);
			x++;
		}
		x = 0;
		y++;
	}
	ft_draw_player(g, img);
}
