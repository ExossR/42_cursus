/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeyre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:50:48 by aribeyre          #+#    #+#             */
/*   Updated: 2022/10/06 13:58:51 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_fill_display(char *filename, char *display)
{
	int		sizestr;
	char	*buf;

	buf = prep_firstline(filename);
	sizestr = ft_strlen(buf);
	display[0] = buf[sizestr - 3];
	display[1] = buf[sizestr - 2];
	display[2] = buf[sizestr - 1];
	display[3] = '\0';
	free(buf);
}

void	ft_free(char **board, char *display, t_square *next, t_square *biggest)
{
	free(board);
	free(display);
	free(next);
	free(biggest);
}

int	solve_puzzle(char *filename)
{
	char		**board;
	t_square	*biggest;
	t_square	*next;
	char		*display;

	display = malloc(sizeof(char) * 4);
	ft_fill_display(filename, display);
	next = (t_square *)malloc(sizeof(int) * 5);
	biggest = (t_square *)malloc(sizeof(int) * 5);
	board = ft_board(filename, next);
	next->posx = 0;
	next->posy = 0;
	next->size = 0;
	biggest->posx = 0;
	biggest->posy = 0;
	biggest->size = 0;
	biggest->boardx = next->boardx;
	biggest->boardy = next->boardy;
	ft_solve_board(board, display, biggest, next);
	display_solution(board, biggest, display);
	ft_free(board, display, next, biggest);
	return (1);
}

void	ft_solve_board(char **board, char *disp, t_square *big, t_square *next)
{
	int		x;
	int		y;
	int		fail;

	fail = 0;
	while (fail == 0)
	{
		y = next->posy;
		while (y <= (next->posy + next->size) && fail == 0)
		{
			x = next->posx;
			while (x <= (next->posx + next->size) && fail == 0)
			{
				if (x >= next->boardx - 1 || y >= next->boardy
					|| board[y][x] == disp[1])
					fail = 1;
				x++;
			}
			y++;
		}
		if (fail == 0)
			next->size = next->size + 1;
		else if (ft_square_cmp(next, big) == 1)
			fail = 0;
	}
}

int	ft_square_cmp(t_square *next, t_square *biggest)
{
	if (next->size > biggest->size)
	{
		biggest->posx = next->posx;
		biggest->posy = next->posy;
		biggest->size = next->size;
	}
	if (next->posx + 1 + biggest->size >= next->boardx)
	{
		if (next->posy + 1 + biggest->size >= next->boardy)
			return (0);
		else
		{
			next->posx = 0;
			next->posy = next->posy + 1;
		}
	}
	else
		next->posx = next->posx + 1;
	return (1);
}
