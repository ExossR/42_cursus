/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:12:26 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/21 14:18:40 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixels + (y * data->line_size + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
}

t_image	ft_new_image(t_game *g, int x, int y)
{
	t_image	img;

	img.ref = mlx_new_image(g->mlx, x, y);
	img.pixels = mlx_get_data_addr(img.ref, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.ref, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

static void	ft_set_vectors(t_game *g)
{
	g->v_dir.dx = cos(g->play.dir);
	g->v_dir.dy = sin(g->play.dir);
	g->v_plan.dx = g->v_dir.dy * -1 * 0.5;
	g->v_plan.dy = g->v_dir.dx * 0.5;
}

int	ft_loop_handler(t_game *g)
{
	ft_mouse(g);
	ft_set_vectors(g);
	ft_move_player(g);
	if (g->frame % 2 == 0)
	{
		ft_draw_minimap(g, &g->mmap);
		ft_draw_3d(g, &g->game3d);
		mlx_put_image_to_window(g->mlx, g->window.ref, g->game3d.ref, 0, 0);
		mlx_put_image_to_window(g->mlx, g->window.ref, g->mmap.ref, 10, 10);
		ft_display_hud(g);
	}
	else
	{
		ft_draw_minimap(g, &g->mmap2);
		ft_draw_3d(g, &g->game3d2);
		mlx_put_image_to_window(g->mlx, g->window.ref, g->game3d2.ref, 0, 0);
		mlx_put_image_to_window(g->mlx, g->window.ref, g->mmap2.ref, 10, 10);
		ft_display_hud(g);
	}
	g->frame++;
	if (g->frame == 48)
		g->frame = 0;
	ft_player_display(g, g->frame);
	return (0);
}
