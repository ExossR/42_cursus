/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeyre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:53:46 by aribeyre          #+#    #+#             */
/*   Updated: 2022/10/06 10:35:58 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_board_size(char *filename, t_square *next)
{
	char	tmp;
	int		fd;

	next->boardy = 0;
	next->boardx = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, &tmp, 1) != 0)
	{
		if (tmp == '\n')
			next->boardy++;
		if (next->boardy == 1)
			next->boardx++;
	}
	next->boardy--;
	close(fd);
}

char	**ft_board(char *filename, t_square *next)
{
	char	tmp;
	char	**board;
	int		i;

	tmp = 'a';
	ft_board_size(filename, next);
	board = malloc(sizeof(char *) * next->boardy);
	i = 0;
	while (i < next->boardy)
	{
		board[i] = malloc(sizeof(char) * next->boardx);
		if (board[i] == NULL)
			return (0);
		i++;
	}
	ft_fill_board(filename, board, tmp);
	return (board);
}

void	ft_fill_board(char *filename, char **board, char tmp)
{
	int		i;
	int		j;
	int		fd;

	fd = open(filename, O_RDONLY);
	tmp = 'a';
	while (tmp != '\n')
		read(fd, &tmp, 1);
	i = 0;
	j = 0;
	while (read(fd, &tmp, 1) != 0)
	{
		if (tmp == '\n')
		{
			board[i][j] = '\0';
			i++;
			j = 0;
		}
		else
		{
			board[i][j] = tmp;
			j++;
		}
	}
	close(fd);
}
