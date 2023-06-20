/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:12:27 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/20 17:15:43 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_void_color_number(char *color)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (color[i])
	{
		if (color[i] == ' ')
			size++;
		i++;
	}
	if (size == ft_strlen(color))
		return (0);
	return (1);
}

int	ft_check_color_format(char **color, t_data *g)
{
	int	i;
	int	nb;
	int	nb_temp;

	i = 0;
	g->nb_colors = 3;
	nb = 0;
	while (i < g->nb_colors)
	{
		if (!color[i] || !ft_void_color_number(color[i]))
			return (0);
		nb_temp = ft_atoi(color[i]);
		if (nb_temp < 0 || nb_temp > 255)
			return (0);
		nb++;
		i++;
	}
	if (nb != 3)
	{
		ft_free_splitted_base(color);
		return (0);
	}
	return (1);
}

int	ft_check_color_arg(char *arg)
{
	int	i;
	int	sign;

	i = 2;
	sign = 0;
	if (ft_strlen(arg) < 7)
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != ' ' && arg[i] != ',')
			return (0);
		if (arg[i] == ',')
			sign++;
		i++;
	}
	if (sign != 2)
		return (0);
	return (1);
}

int	ft_check_colors(t_data *g, char *color)
{
	int		i;
	char	**split;

	g->tmp_nb = 0;
	i = 0;
	while (i < g->filey && !ft_valid_maplign(g->file[i]))
	{
		if (ft_strnstr(g->file[i], color, 2))
		{
			g->tmp_nb++;
			if (!ft_check_color_arg(g->file[i]))
				return (0);
			split = ft_split(&g->file[i][2], ',');
			if (!ft_check_color_format(split, g) || g->tmp_nb != 1)
			{
				ft_free_splitted_base(split);
				return (0);
			}
			ft_free_splitted_base(split);
		}
		i++;
	}
	if (g->tmp_nb != 1)
		return (0);
	return (1);
}
