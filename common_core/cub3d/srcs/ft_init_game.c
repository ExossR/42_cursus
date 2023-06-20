/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:12:43 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/23 15:07:28 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.ref = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	mlx_hook(window.ref, 17, 0, ft_close, 0);
	return (window);
}

static double	ft_convert_dir(t_data *data)
{
	if (data->spawn_dir == 'S')
		return (M_PI_2);
	else if (data->spawn_dir == 'N')
		return (-M_PI_2);
	else if (data->spawn_dir == 'E')
		return (0);
	else
		return (M_PI);
}

static void	ft_init_colors(t_game *g, t_data *data)
{
	char	**ceiling;
	char	**floor;

	ceiling = ft_split(data->ceiling_color, ',');
	floor = ft_split(data->floor_color, ',');
	g->ccolor.r = ft_atoi(ceiling[0]);
	g->ccolor.g = ft_atoi(ceiling[1]);
	g->ccolor.b = ft_atoi(ceiling[2]);
	g->ccolor.t = 0;
	g->ccolor.color = g->ccolor.t << 24 | g->ccolor.r << 16
		| g->ccolor.g << 8 | g->ccolor.b;
	ft_free_splitted(ceiling, 3);
	g->fcolor.r = ft_atoi(floor[0]);
	g->fcolor.g = ft_atoi(floor[1]);
	g->fcolor.b = ft_atoi(floor[2]);
	ft_free_splitted(floor, 3);
	g->fcolor.t = 0;
	g->fcolor.color = g->fcolor.t << 24 | g->fcolor.r << 16
		| g->fcolor.g << 8 | g->fcolor.b;
}

static void	ft_duplicate_map(t_game *game, t_data *data)
{
	int	i;

	i = 0;
	game->map = ft_calloc(sizeof(char *), (data->map_sy + 1));
	while (data->maps[i])
	{
		game->map[i] = ft_strdup(data->maps[i]);
		i++;
	}
	game->map[i] = NULL;
}

void	ft_init_game(t_game *game, t_data *data)
{
	ft_duplicate_map(game, data);
	ft_init_colors(game, data);
	game->play.dx = (double)data->play_posx + 0.5;
	game->play.dy = (double)data->play_posy + 0.5;
	game->ea_sprite = ft_new_sprite(game->mlx, data->ea_sprite);
	game->we_sprite = ft_new_sprite(game->mlx, data->we_sprite);
	game->no_sprite = ft_new_sprite(game->mlx, data->no_sprite);
	game->so_sprite = ft_new_sprite(game->mlx, data->so_sprite);
	game->map_s.x = data->map_sx;
	game->map_s.y = data->map_sy;
	game->play.dir = ft_convert_dir(data);
	ft_init_datas(game);
	mlx_mouse_move(game->window.ref, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	game->mun = 17;
	game->fire = 0;
}
