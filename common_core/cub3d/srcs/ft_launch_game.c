/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:27:42 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/23 15:18:47 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_close(t_game *g)
{
	(void) g;
	exit (0);
}

int	all_xpm_ok(t_game *g, t_data *data)
{
	void	*mlx;

	mlx = g->mlx;
	if (verif_xpm(mlx, data->no_sprite) || verif_xpm(mlx, data->so_sprite)
		|| verif_xpm(mlx, data->ea_sprite)
		|| verif_xpm(mlx, data->we_sprite))
		return (1);
	if (verif_xpm(mlx, "sprites/player.xpm")
		|| verif_xpm(mlx, "sprites/player-fire.xpm")
		|| verif_xpm(mlx, "sprites/hud.xpm")
		|| verif_xpm(mlx, "sprites/mun.xpm"))
		return (1);
	return (0);
}

void	ft_launch_game(t_data *data)
{
	t_game	*g;

	g = malloc(sizeof(t_game));
	g->mlx = mlx_init();
	g->window = ft_new_window(g->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D v1");
	if (all_xpm_ok(g, data) == 1)
	{
		printf("Error.\nA xpm files is invalid.\n");
		ft_exit(data, 4);
		ft_close(g);
		return ;
	}
	g->mouse_lock = 1;
	ft_init_game(g, data);
	mlx_hook(g->window.ref, 02, (1L << 0), ft_key_press_handler, g);
	mlx_key_hook(g->window.ref, ft_key_release_handler, g);
	mlx_loop_hook(g->mlx, ft_loop_handler, g);
	mlx_mouse_hook(g->window.ref, ft_mouse_click, g);
	mlx_loop(g->mlx);
}
