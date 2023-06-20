/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:27:33 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/23 16:09:07 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_path_finding(t_data *g, int y, int x)
{
	if (y < 0 || x < 0 || x == g->map_sx + 1 || y == g->map_sy + 1
		|| g->map_temp[y][x] == '1' || g->map_temp[y][x] == '.')
		return ;
	if (g->map_temp[y][x] == ' ')
		g->map_temp[y][x] = '.';
	else
	{
		g->map_temp[y][x] = 'X';
		g->error++;
		return ;
	}
	ft_path_finding(g, y, x - 1);
	ft_path_finding(g, y, x + 1);
	ft_path_finding(g, y - 1, x);
	ft_path_finding(g, y + 1, x);
}

void	ft_launch_path_finding(t_data *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->map_sy + 2)
	{
		x = 0;
		while (g->map_temp[y][x])
		{
			if (g->map_temp[y][x] == ' ')
				ft_path_finding(g, y, x);
			x++;
		}
		y++;
	}
}

static int	ft_is_valid_char(char c)
{
	if (c != ' ' && c != '1' && c != '0' && c != 'S' && c != 'N' && c != 'E'
		&& c != 'W')
		return (0);
	return (1);
}

int	ft_is_valid_position(t_data *g)
{
	int	i;
	int	j;

	i = -1;
	g->spawn_point = 0;
	while (++i < g->map_sy)
	{
		j = -1;
		while (g->maps[i][++j])
		{
			if (g->maps[i][j] == 'S' || g->maps[i][j] == 'N'
				|| g->maps[i][j] == 'E' || g->maps[i][j] == 'W')
			{
				g->spawn_point++;
				g->spawn_dir = g->maps[i][j];
				g->maps[i][j] = '0';
			}
			else if (!ft_is_valid_char(g->maps[i][j]))
				g->error++;
		}
	}
	if (g->spawn_point != 1 || g->error > 0)
		return (0);
	return (1);
}

int	ft_is_valid_map(t_data *g)
{
	g->error = 0;
	ft_create_temp_map(g);
	ft_create_temp_map2(g);
	ft_launch_path_finding(g);
	ft_find_playerition(g);
	ft_free_splitted(g->map_temp, g->map_sy + 2);
	if (!ft_is_valid_position(g) || g->error > 0)
	{
		ft_exit(g, 4);
		printf("Error.\nWrong map format.\n");
		return (0);
	}
	return (1);
}
