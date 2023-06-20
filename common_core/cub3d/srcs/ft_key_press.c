/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:38:03 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/17 08:59:30 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press_up_down(int keycode, t_game *g)
{
	if (keycode == DOWN)
		g->move.down = true;
	else if (keycode == UP)
		g->move.up = true;
	return (0);
}

int	key_press_right_left(int keycode, t_game *g)
{
	if (keycode == LEFT)
		g->move.left = true;
	else if (keycode == RIGHT)
		g->move.right = true;
	return (0);
}

int	key_press_rotate(int keycode, t_game *g)
{
	if (keycode == RLEFT)
		g->move.lrot = true;
	else if (keycode == RRIGHT)
		g->move.rrot = true;
	return (0);
}

int	comb_key_press(int keycode, t_game *g)
{
	if (keycode == DOWN && (RIGHT == true || LEFT == true
			|| RRIGHT == true || RLEFT == true))
		g->move.down = true;
	else if (keycode == UP && (RIGHT == true || LEFT == true
			|| RRIGHT == true || RLEFT == true))
		g->move.up = true;
	else if (keycode == RIGHT && (UP == true || DOWN == true
			|| RRIGHT == true || RLEFT == true))
		g->move.right = true;
	else if (keycode == LEFT && (UP == true || DOWN == true
			|| RRIGHT == true || RLEFT == true))
		g->move.left = true;
	else if (keycode == RRIGHT && (UP == true || DOWN == true
			|| RIGHT == true || LEFT == true))
		g->move.rrot = true;
	else if (keycode == RLEFT && (UP == true || DOWN == true
			|| RIGHT == true || LEFT == true))
		g->move.lrot = true;
	return (0);
}

int	ft_key_press_handler(int keycode, t_game *g)
{
	comb_key_press(keycode, g);
	key_press_up_down(keycode, g);
	key_press_right_left(keycode, g);
	key_press_rotate(keycode, g);
	if (keycode == ESCAPE)
		ft_close(g);
	if (keycode == 125)
		g->mouse_lock = 0;
	return (0);
}
