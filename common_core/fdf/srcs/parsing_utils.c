/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:08:21 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/05 11:34:36 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

char	*get_last_line(char *path)
{
	int		op;
	char	*buff;
	char	*next_next_line;

	buff = 0;
	op = open(path, O_RDONLY);
	next_next_line = "";
	while (next_next_line != 0)
	{
		next_next_line = get_next_line(op);
		if (next_next_line != 0)
		{
			if (buff != 0)
				free(buff);
			buff = next_next_line;
		}
	}
	return (buff);
	close(op);
}

int	map_arg_y(char *path)
{
	int		count;
	char	*buff;
	int		op;

	op = open(path, O_RDONLY);
	count = 0;
	buff = get_next_line(op);
	while (buff != 0)
	{
		count++;
		free(buff);
		buff = get_next_line(op);
	}
	close(op);
	free(buff);
	return (count);
}

int	map_arg_x(char *path)
{
	char	*buff;
	int		count;
	int		i;

	i = 0;
	count = 0;
	buff = get_last_line(path);
	while (buff[i] != '\0')
	{
		if (buff[i] != ' ' && buff[i] != '\0')
		{
			while (buff[i] != ' ' && buff[i] != '\0')
				i++;
			count++;
		}
		else
			i++;
	}
	free(buff);
	return (count);
}

void	set_coordonate(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}
