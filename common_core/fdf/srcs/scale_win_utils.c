/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_win_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:53:51 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/29 13:54:25 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	count_y(t_point **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	count_x(t_point **map)
{
	int	i;

	i = 0;
	while (map[0][i].x != -1)
		i++;
	return (i);
}
