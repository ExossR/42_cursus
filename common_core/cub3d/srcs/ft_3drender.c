/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3drender.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:51:05 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/16 19:12:32 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_get_img_pixel_color(t_image *img, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = img->pixels + (y * img->line_size + x * (img->bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

void	ft_draw_wall_texture(t_game *g, t_image *img, t_image *t)
{
	int		texture_x;
	int		texture_y;
	double	wallx;
	int		color;

	if (g->ray.side == 0)
		wallx = g->play.dy + g->ray.perpwalldist * g->ray.raydir_y;
	else
		wallx = g->play.dx + g->ray.perpwalldist * g->ray.raydir_x;
	wallx -= floor((wallx));
	if (g->draw_dest.dir == 0)
		texture_x = (int)(wallx * t->line_size / 4);
	else
		texture_x = t->size.x - (int)(wallx * t->line_size / 4) - 1;
	if (g->ray.linetrueheight == 0)
		texture_y = (int)(t->size.y * (g->draw_dest.y - (SCREEN_HEIGHT
						- g->ray.lineheight) / 2) / g->ray.lineheight);
	else
		texture_y = (int)(t->size.y * (g->draw_dest.y - (SCREEN_HEIGHT
						- g->ray.linetrueheight) / 2) / g->ray.linetrueheight);
	color = ft_get_img_pixel_color(t, texture_x, texture_y);
	my_mlx_pixel_put(img, g->draw_dest.x, g->draw_dest.y, color);
}

static void	ft_draw_line_3d_dir(t_game *g, t_image *img, int i, int col)
{
	g->draw_dest.x = col;
	g->draw_dest.y = i;
	g->draw_dest.dir = 0;
	if (g->ray.side == 0)
	{
		if (g->ray.mapx - g->play.dx < 0)
		{
			g->draw_dest.dir = 1;
			ft_draw_wall_texture(g, img, &g->we_sprite);
		}
		else
			ft_draw_wall_texture(g, img, &g->ea_sprite);
	}
	else if (g->ray.side == 1)
	{
		if (g->ray.mapy - g->play.dy < 0)
			ft_draw_wall_texture(g, img, &g->no_sprite);
		else
		{
			g->draw_dest.dir = 1;
			ft_draw_wall_texture(g, img, &g->so_sprite);
		}
	}
}

static void	ft_draw_line_3d(t_game *g, t_image *img, int size, int col)
{
	int	i;

	i = 0;
	while (i < ((SCREEN_HEIGHT - size) / 2))
	{
		my_mlx_pixel_put(img, col, i, g->ccolor.color);
		i++;
	}
	while (i < (size + (SCREEN_HEIGHT - size) / 2))
	{
		ft_draw_line_3d_dir(g, img, i, col);
		i++;
	}
	while (i < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(img, col, i, g->fcolor.color);
		i++;
	}
}

void	ft_draw_3d(t_game *g, t_image *img)
{
	int	ray;

	ray = 0;
	while (ray < SCREEN_WIDTH)
	{
		ft_init_ray(g, ray);
		ft_calc_step_distance(g);
		ft_check_wall_collision(g);
		ft_calc_dist_high(g);
		ft_draw_line_3d(g, img, g->ray.lineheight, ray);
		ray++;
	}
}
