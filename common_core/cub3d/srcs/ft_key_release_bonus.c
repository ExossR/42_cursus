/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_release_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:40:10 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/19 17:48:30 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	key_release_up_down(int keycode, t_game *g)
{
	if (keycode == DOWN)
		g->move.down = false;
	else if (keycode == UP)
		g->move.up = false;
	return (0);
}

int	key_release_right_left(int keycode, t_game *g)
{
	if (keycode == LEFT)
		g->move.left = false;
	else if (keycode == RIGHT)
		g->move.right = false;
	return (0);
}

int	key_release_rotate(int keycode, t_game *g)
{
	if (keycode == RLEFT)
		g->move.lrot = false;
	else if (keycode == RRIGHT)
		g->move.rrot = false;
	return (0);
}

int	ft_key_release_handler(int keycode, t_game *g)
{
	key_release_up_down(keycode, g);
	key_release_right_left(keycode, g);
	key_release_rotate(keycode, g);
	return (0);
}
