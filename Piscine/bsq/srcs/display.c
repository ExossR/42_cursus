/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeyre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:53:08 by aribeyre          #+#    #+#             */
/*   Updated: 2022/10/06 10:33:30 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_solution(char **board, t_square *b, char *display)
{
	int		i;
	int		j;

	i = 0;
	while (i < b->boardy)
	{
		j = 0;
		while (j < b->boardx)
		{
			if (i >= b->posy && i <= (b->posy + b->size - 1) && j >= b->posx
				&& j <= (b->posx + b->size - 1))
				write(1, &display[2], 1);
			else
				write(1, &board[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}
