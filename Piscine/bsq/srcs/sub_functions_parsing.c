/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_functions_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:47:47 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/06 01:25:37 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	size_firstline(char *path)
{
	int		i;
	int		op;
	char	letter;

	i = 0;
	op = open(path, O_RDONLY);
	if (op == -1)
		return (0);
	while (read(op, &letter, 1) != 0 && letter != '\n')
		i++;
	close(op);
	return (i);
}

int	size_line(char *path)
{
	int		i;
	int		op;
	int		fl;
	char	letter;

	i = 0;
	fl = 0;
	op = open(path, O_RDONLY);
	while (read(op, &letter, 1) != 0 && fl < 2)
	{
		if (letter == '\n')
			fl++;
		if (fl == 1)
			i++;
	}
	close(op);
	return (i);
}

int	ft_nbline_to_int(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

void	ft_strcat_but_only_one(char *dest, char src)
{
	int	sizedest;

	sizedest = ft_strlen(dest);
	dest[sizedest] = src;
	sizedest++;
	dest[sizedest] = '\0';
}

char	**ft_firstline(char *buf, int sizefl, int i, int j)
{
	char	**firstline;

	firstline = malloc(5 * sizeof(char *));
	firstline[0] = malloc((sizefl - 3) * sizeof(char));
	firstline[0][0] = '\0';
	if (firstline == 0 || firstline[0] == 0)
		return (0);
	while (buf[j] && j < (sizefl - 3) && (buf[j] >= 48 && buf[j] <= 57))
	{
		ft_strcat_but_only_one(firstline[0], buf[j]);
		j++;
	}
	ft_strcat_but_only_one(firstline[0], '\0');
	i = 1;
	while (i < 4)
	{
		firstline[i] = malloc(2 * sizeof(char));
		firstline[i][0] = buf[j];
		firstline[i][1] = '\0';
		j++;
		i++;
	}
	firstline[i] = 0;
	return (firstline);
}
