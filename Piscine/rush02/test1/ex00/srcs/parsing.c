/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:18:22 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/02 22:56:11 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		wash_string(char *str);

int			count_line(char *path);

void	initializer_create_array(char *buff, int *i)
{
	buff[0] = '\0';
	*i = 0;
}

char	*ft_strcat_only_one(char *dest, char src)
{
	int	i;
	int	sizedest;

	i = 0;
	sizedest = ft_strlen(dest);
	while (i < sizedest)
	{
		if (dest[i] == '\0')
			break ;
		i++;
	}
	dest[i] = src;
	i++;
	dest[i] = '\0';
	return (dest);
}

char	*find_trad(char *target, t_number **tab)
{
	int	i;

	i = 0;
	while (tab[i]->number != 0)
	{
		if (ft_strcmp(tab[i]->number, target) == 0)
			return (tab[i]->str);
		i++;
	}
	return (0);
}

void	creating_array(t_number **tab, char *path)
{
	char	letter;
	char	buff[256];
	int		file;
	int		i;

	initializer_create_array(buff, &i);
	file = open(path, O_RDONLY);
	tab[0] = malloc (sizeof(t_number));
	while (read(file, &letter, 1) != 0)
	{
		if (letter == ':')
		{
			tab[i]->number = ft_strdup(buff);
			wash_string(buff);
		}
		else if (letter == '\n')
		{
			tab[i]->str = ft_strdup(buff);
			wash_string(buff);
			tab[++i] = malloc (sizeof(t_number));
		}
		else
			ft_strcat_only_one(buff, letter);
	}
	close(file);
}

void	wash_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
}
