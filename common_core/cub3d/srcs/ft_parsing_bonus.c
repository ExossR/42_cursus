/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:01:34 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/23 16:18:37 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

char	*ft_adapt_line(char *line, int target_size)
{
	int		original_size;
	char	*padded_line;

	original_size = ft_strlen(line);
	padded_line = (char *)ft_calloc(target_size + 1, sizeof(char));
	if (!padded_line)
		return (NULL);
	ft_memcpy(padded_line, line, original_size);
	ft_memset(padded_line + original_size, ' ', target_size - original_size);
	return (padded_line);
}

void	ft_simplify_map(t_data *g)
{
	int		i;
	size_t	len_max;
	char	**new_map;

	i = 0;
	len_max = ft_strlen(g->map[i]);
	new_map = ft_calloc(sizeof(char *), (ft_size_map(g) + 1));
	while (i < g->map_sy)
	{
		if (g->map[i] && ft_strlen(g->map[i]) > len_max)
			len_max = ft_strlen(g->map[i]);
		i++;
	}
	i = 0;
	while (g->map[i] && i < g->map_sy)
	{
		new_map[i] = ft_adapt_line(g->map[i], len_max + 1);
		i++;
	}
	new_map[g->map_sy] = NULL;
	g->maps = new_map;
	g->map_sx = (int)len_max + 1;
	ft_free_splitted(g->map, g->map_sy);
}

void	ft_save_map(t_data *g, int size_map)
{
	int		i;
	char	**map;
	int		j;

	i = 0;
	j = 0;
	map = ft_calloc(sizeof(char *), size_map);
	while (i < g->filey && !ft_valid_maplign2(g->file[i]))
		i++;
	while (i < g->filey && ft_valid_maplign2(g->file[i]))
	{
		map[j] = ft_strdup(g->file[i]);
		i++;
		j++;
	}
	g->map = map;
}

int	ft_size_map(t_data *g)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (i < g->filey && !ft_valid_maplign2(g->file[i]))
		i++;
	while (i < g->filey && ft_valid_maplign2(g->file[i]))
	{
		size++;
		i++;
	}
	if (i < g->filey)
		return (-1);
	g->map_sy = size;
	return (size);
}

int	ft_parse_map(t_data *game_data)
{
	if (!ft_check_parasite(game_data))
		return (0);
	if (!ft_check_texture(game_data))
		return (0);
	if (ft_size_map(game_data) == -1)
	{
		ft_exit(game_data, 3);
		printf("Error.\nWrong map format.\n");
		return (0);
	}
	ft_save_map(game_data, game_data->map_sy);
	ft_simplify_map(game_data);
	if (!ft_is_valid_map(game_data))
		return (0);
	ft_launch_game(game_data);
	return (1);
}
