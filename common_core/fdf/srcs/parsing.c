/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:16:43 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/09 17:18:35 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	find_n_value(char *str, int n)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\n' || str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			if (count == n)
				return (ft_atoi(&str[i]));
			while (str[i] != ' ' && str[i] != '\0')
				i++;
			count++;
		}
		else
			i++;
	}
	return (-1);
}

t_point	**read_map(int x_size, int y_size, int fd)
{
	char	*buff;
	t_point	**output;
	int		x;
	int		y;

	x = 0;
	output = malloc(sizeof(t_point *) * (y_size + 1));
	buff = get_next_line(fd);
	while (buff)
	{
		output[x] = malloc(sizeof(t_point) * (x_size + 1));
		y = 0;
		while (y < x_size - 1)
		{
			set_coordonate(&output[x][y], x, y, find_n_value(buff, y));
			y++;
		}
		set_coordonate(&output[x][y], -1, -1, -1);
		x++;
		free(buff);
		buff = get_next_line(fd);
	}
	output[x] = 0;
	return (output);
}

t_point	**init_map_read(char *path)
{
	int		x_size;
	int		y_size;
	t_point	**output;
	int		fd;

	x_size = map_arg_x(path);
	y_size = map_arg_y(path);
	fd = open(path, O_RDONLY);
	output = read_map(x_size, y_size, fd);
	close(fd);
	return (output);
}
