/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:52:32 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/23 16:18:19 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_print_file(t_data *game_data)
{
	int	i;

	i = 0;
	printf("Start File----------------------------------------\n");
	while (i < game_data->filey)
	{
		printf("|%s|\n", game_data->file[i]);
		i++;
	}
	printf("End File-----------------------------------------\n");
}

void	ft_print_game_data2(t_data *game_data)
{
	int	i;

	i = 0;
	printf("Start Map_TEMP-----------------------------------------\n");
	while (i < game_data->map_sy + 2)
	{
		printf("|%s|\n", game_data->map_temp[i]);
		i++;
	}
	printf("End Map_TEMP-----------------------------------------\n");
	printf("Map error : %d\n", game_data->error);
}

void	ft_print_all(t_data *g)
{
	int	i;

	printf("NO sprite : %s\n", g->no_sprite);
	printf("SO sprite : %s\n", g->so_sprite);
	printf("EA sprite : %s\n", g->ea_sprite);
	printf("WE sprite : %s\n", g->we_sprite);
	printf("Floor color : %s\n", g->floor_color);
	printf("Ceiling color : %s\n", g->ceiling_color);
	printf("Player position : %dy,%dx\n", g->play_posy, g->play_posx);
	printf("Size map : %dy,%dx\n", g->map_sx, g->map_sy);
	i = 0;
	while (g->maps[i])
	{
		printf("%s\n", g->maps[i]);
		i++;
	}
}

void	ft_print_ray(t_game *g, int ray)
{
	printf("Ray %d\n", ray);
	printf("Camera X : %f\n", g->ray.camera_x);
	printf("rayDir : %f,%f\n", g->ray.raydir_x, g->ray.raydir_y);
	printf("deltaDist : %f,%f\n", g->ray.deltadist_x, g->ray.deltadist_y);
	printf("map : %d,%d\n", g->ray.mapx, g->ray.mapy);
	printf("step : %d,%d\n", g->ray.stepx, g->ray.stepy);
	printf("sideDist : %f,%f\n", g->ray.sidedist_x, g->ray.sidedist_y);
	printf("hit : %d\n", g->ray.hit);
	printf("perpwalldist : %f\n", g->ray.perpwalldist);
	printf("lineheight : %d\n", g->ray.lineheight);
	printf("----------------------------------------------------\n");
}
