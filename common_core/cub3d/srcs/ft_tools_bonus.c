/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:50:14 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/19 17:48:46 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_free_splitted(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free (str[i]);
		i++;
	}
	free (str);
}

void	ft_free_splitted_base(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

void	ft_create_temp_map(t_data *g)
{
	char	**map_temp;
	int		y;
	int		x;

	y = 0;
	map_temp = ft_calloc(sizeof(char *), (g->map_sy + 2));
	while (y < g->map_sy)
	{
		x = 0;
		map_temp[y + 1] = ft_calloc(sizeof(char), (g->map_sx + 3));
		while (g->maps[y][x])
		{
			map_temp[y + 1][0] = ' ';
			map_temp[y + 1][x + 1] = g->maps[y][x];
			x++;
		}
		map_temp[y + 1][x + 1] = ' ';
		map_temp[y + 1][x + 2] = '\0';
		y++;
	}
	g->map_temp = map_temp;
}

void	ft_create_temp_map2(t_data *g)
{
	int	i;

	i = 0;
	g->map_temp[0] = ft_calloc(sizeof(char), (g->map_sx + 3));
	g->map_temp[g->map_sy + 1] = ft_calloc(sizeof(char), (g->map_sx + 3));
	while (i < g->map_sx + 2)
	{
		g->map_temp[0][i] = ' ';
		g->map_temp[g->map_sy + 1][i] = ' ';
		i++;
	}
	g->map_temp[0][g->map_sx + 2] = '\0';
	g->map_temp[g->map_sy + 1][g->map_sx + 2] = '\0';
}
