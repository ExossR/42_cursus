/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:58:44 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/06 14:11:38 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	verif_nbline(char *path, int nbline)
{
	int		op;
	int		nblinemax;
	int		firstline;
	char	letter;

	op = open(path, O_RDONLY);
	firstline = 0;
	if (op == -1)
		return (0);
	while (read(op, &letter, 1) != 0)
	{
		if (letter == '\n')
			firstline++;
		else if (!(letter >= 32 && letter <= 126))
			return (0);
	}
	close(op);
	nblinemax = nbline;
	if (nblinemax != firstline - 1)
		return (0);
	return (1);
}

int	verif_char(char *path, char c_void, char c_bloc, char c_full)
{
	int		i;
	int		op;
	int		sizeline;
	int		firstline;
	char	letter;

	i = 0;
	sizeline = size_line(path);
	op = open(path, O_RDONLY);
	firstline = 0;
	while (read(op, &letter, 1) != 0)
	{
		if (i < sizeline && firstline > 0
			&& !((letter == c_bloc || letter == c_void) && letter != c_full))
			return (0);
		if (letter == '\n')
		{
			i = 0;
			firstline++;
		}
		i++;
	}
	close(op);
	return (1);
}

int	verif_sizeline(char *path, int i, int firstline)
{
	int		op;
	int		sizeline;
	char	letter;

	sizeline = size_line(path);
	op = open(path, O_RDONLY);
	while (read(op, &letter, 1) != 0)
	{
		if (letter == '\n')
		{
			if (firstline > 1)
				if (sizeline - 1 != i)
					return (0);
			i = 0;
			firstline++;
		}
		else if (firstline > 0)
			i++;
	}
	close(op);
	return (1);
}

char	*prep_firstline(char *path)
{
	int		i;
	int		op;
	char	letter;
	char	*buf;

	i = size_firstline(path);
	if (i < 4)
		return (0);
	buf = malloc(i * sizeof(char));
	op = open(path, O_RDONLY);
	while (read(op, &letter, 1) != 0 && letter != '\n')
		ft_strcat_but_only_one(buf, letter);
	close(op);
	return (buf);
}

int	ft_verif_parsing(char *path, int nbline)
{
	char	c_void;
	char	c_bloc;
	char	c_full;
	char	*buf;
	char	**str_fl;

	buf = prep_firstline(path);
	if (buf == 0)
		return (0);
	str_fl = ft_firstline(buf, size_firstline(path), 0, 0);
	nbline = ft_nbline_to_int(str_fl[0]);
	c_void = str_fl[1][0];
	c_bloc = str_fl[2][0];
	c_full = str_fl[3][0];
	if (verif_nbline(path, nbline) == 0)
		return (0);
	if (verif_char(path, c_void, c_bloc, c_full) == 0)
		return (0);
	if (verif_sizeline(path, 0, 0) == 0)
		return (0);
	free(buf);
	free(str_fl);
	return (1);
}
