/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_file_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:22:07 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/19 17:48:00 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	ft_is_map_empty(char *input)
{
	if (!ft_file_size(input))
	{
		printf("Error.\nEmpty map.\n");
		return (0);
	}
	return (1);
}

int	ft_check_file(char *input)
{
	int	fd;

	if (!ft_strnstr(&input[(ft_strlen(input) - 4)], ".cub", 4))
	{
		printf("Error.\nBad file extension.\n");
		return (0);
	}
	fd = open(input, O_DIRECTORY);
	if (fd != -1)
	{
		printf("Error.\n%s is a directory.\n", input);
		close (fd);
		return (0);
	}
	else
	{
		fd = open(input, O_RDONLY);
		if (fd == -1)
		{
			printf("Error.\n%s no such file or directory.\n", input);
			return (0);
		}
	}
	close(fd);
	return (1);
}

int	ft_file_size(char *input)
{
	int		fd;
	int		len;
	char	*temp;

	len = 0;
	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		free(temp);
		len++;
	}
	free(temp);
	close (fd);
	return (len);
}

char	**ft_save_file(char *input, t_data *g)
{
	int		fd;
	char	**map;
	int		i;
	int		size_file;

	i = 0;
	g->filey = 0;
	size_file = ft_file_size(input);
	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (0);
	map = ft_calloc(sizeof(char *), size_file);
	if (!map)
		return (0);
	while (i < size_file)
	{
		map[i] = get_next_line(fd);
		if (map[i] && map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
		g->filey++;
	}
	close (fd);
	return (map);
}
