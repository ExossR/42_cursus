/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:16:01 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/20 16:57:21 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_valid_maplign2(char *arg)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) < 1)
		return (0);
	while (arg[i])
	{
		if (arg[i] != ' ' && arg[i] != '1' && arg[i] != '0' && arg[i] != 'N'
			&& arg[i] != 'E' && arg[i] != 'S' && arg[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int	ft_valid_maplign(char *arg)
{
	int	i;

	i = 0;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (arg[i] != ' ' && arg[i] != '1' && arg[i] != '0' && arg[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_parasite(t_data *g)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (i < g->filey - 1)
	{
		if (ft_valid_arg(g->file[i]))
		{
			nb++;
			i++;
		}
		else if (ft_strlen(g->file[i]) == 0)
			i++;
		else
			break ;
	}
	if (nb != 6 || !ft_valid_maplign(g->file[i]))
	{
		printf("Error.\nParasite data in map file.\n");
		return (0);
	}
	return (1);
}

int	ft_valid_arg(char *arg)
{
	if (ft_strnstr(arg, "NO ", 3)
		|| ft_strnstr(arg, "EA ", 3)
		|| ft_strnstr(arg, "WE ", 3)
		|| ft_strnstr(arg, "SO ", 3)
		|| ft_strnstr(arg, "C ", 2)
		|| ft_strnstr(arg, "F ", 2))
		return (1);
	return (0);
}

void	ft_find_playerition(t_data *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->map_sy)
	{
		x = 0;
		while (g->maps[y][x])
		{
			if ((g->maps[y][x] == 'N') || (g->maps[y][x] == 'E')
				|| (g->maps[y][x] == 'S') || (g->maps[y][x] == 'W'))
			{
				g->play_posx = x;
				g->play_posy = y;
				break ;
			}
			x++;
		}
		y++;
	}
}
