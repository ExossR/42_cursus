/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:51:02 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/04 07:58:45 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_texture_file(char *path)
{
	char	tmp[1];
	int		tmp_size;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	tmp_size = read(fd, tmp, 1);
	if (tmp_size < 1)
		return (0);
	if (!ft_strnstr(&path[(ft_strlen(path) - 4)], ".xpm", 4))
		return (0);
	close(fd);
	return (1);
}

int	ft_check_textures_arg(t_data *g, char *texture)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (i < g->filey)
	{
		if ((g->file[i][0] == '1' || g->file[i][0] == '0') && nb == 0)
			break ;
		if (ft_strnstr(g->file[i], texture, 5))
		{
			nb++;
			if (!ft_check_texture_file(&g->file[i][3]) || nb != 1)
				return (0);
		}
		i++;
	}
	if (nb != 1)
		return (0);
	return (1);
}

int	ft_check_texture(t_data *game_data)
{
	if (!ft_check_textures_arg(game_data, "NO ./")
		|| !ft_check_textures_arg(game_data, "SO ./")
		|| !ft_check_textures_arg(game_data, "WE ./")
		|| !ft_check_textures_arg(game_data, "EA ./"))
	{
		printf("Error.\nProblem with texture.\n");
		return (0);
	}
	if (!ft_check_colors(game_data, "F "))
	{
		printf("Error.\nProblem with floor color.\n");
		return (0);
	}
	if (!ft_check_colors(game_data, "C "))
	{
		printf("Error.\nProblem with ceiling color.\n");
		return (0);
	}
	ft_save_texture_color_data(game_data);
	return (1);
}

void	ft_save_texture_color_data(t_data *g)
{
	int	i;

	i = 0;
	while (i < g->filey && !ft_valid_maplign(g->file[i]))
	{
		if (ft_strnstr(g->file[i], "NO ./", 5))
			g->no_sprite = ft_strdup(&g->file[i][3]);
		else if (ft_strnstr(g->file[i], "SO ./", 5))
			g->so_sprite = ft_strdup(&g->file[i][3]);
		else if (ft_strnstr(g->file[i], "EA ./", 5))
			g->ea_sprite = ft_strdup(&g->file[i][3]);
		else if (ft_strnstr(g->file[i], "WE ./", 5))
			g->we_sprite = ft_strdup(&g->file[i][3]);
		else if (ft_strnstr(g->file[i], "F ", 2))
			g->floor_color = ft_strdup(&g->file[i][2]);
		else if (ft_strnstr(g->file[i], "C ", 2))
			g->ceiling_color = ft_strdup(&g->file[i][2]);
		i++;
	}
}
