/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:35:30 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/17 11:51:19 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_wall_slip(t_game *g, double x, double y, int sign)
{
	if (sign == 0)
	{
		if (g->map[(int)(g->play.dy - y)][(int)(g->play.dx)] == '0')
			g->play.dy -= y;
		else if (g->map[(int)(g->play.dy)][(int)(g->play.dx - x)] == '0')
			g->play.dx -= x;
	}
	else
	{
		if (g->map[(int)(g->play.dy + y)][(int)(g->play.dx)] == '0')
			g->play.dy += y;
		else if (g->map[(int)(g->play.dy)][(int)(g->play.dx + x)] == '0')
			g->play.dx += x;
	}
}

static void	ft_set_npos(t_game *g, double x, double y, int add)
{
	if (add == 0)
	{
		if (g->map[(int)(g->play.dy - y)][(int)(g->play.dx - x)] == '0'
			&& g->map[(int)(g->play.dy + y)][(int)(g->play.dx - x)] == '0')
		{
			g->play.dy -= y;
			g->play.dx -= x;
		}
		else
			ft_wall_slip(g, x, y, 0);
	}
	else
	{
		if (g->map[(int)(g->play.dy + y)][(int)(g->play.dx + x)] == '0'
				&& g->map[(int)(g->play.dy - y)][(int)(g->play.dx + x)] == '0')
		{
			g->play.dy += y;
			g->play.dx += x;
		}
		else
			ft_wall_slip(g, x, y, 1);
	}
}

void	ft_move_player(t_game *g)
{
	if (g->move.left)
		ft_set_npos(g, cos(g->play.dir + M_PI / 2) * M_SPEED,
			sin(g->play.dir + M_PI / 2) * M_SPEED, 0);
	else if (g->move.right)
		ft_set_npos(g, cos(g->play.dir + M_PI / 2) * M_SPEED,
			sin(g->play.dir + M_PI / 2) * M_SPEED, 1);
	if (g->move.down)
		ft_set_npos(g, cos(g->play.dir) * M_SPEED,
			sin(g->play.dir) * M_SPEED, 0);
	else if (g->move.up)
		ft_set_npos(g, cos(g->play.dir) * M_SPEED,
			sin(g->play.dir) * M_SPEED, 1);
	if (g->move.lrot)
		g->play.dir -= M_PI / 36 * R_SPEED;
	else if (g->move.rrot)
		g->play.dir += M_PI / 36 * R_SPEED;
}

int	ft_mouse_click(int click, int x, int y, t_game *g)
{
	(void) g;
	(void) x;
	(void) y;
	if (click == 1 && g->mun > 0)
	{
		g->fire = 1;
		g->mun--;
	}
	else if (click == 2)
		g->mun = 17;
	return (0);
}

void	ft_mouse(t_game *g)
{
	int	mouse_x;
	int	mouse_y;

	if (g->mouse_lock == 1)
	{
		mlx_mouse_hide();
		mlx_mouse_get_pos(g->window.ref, &mouse_x, &mouse_y);
		if (mouse_x < SCREEN_WIDTH / 2)
		g->play.dir -= M_PI / 36 * R_SPEED;
		else if (mouse_x > SCREEN_WIDTH / 2)
			g->play.dir += M_PI / 36 * R_SPEED;
		mlx_mouse_move(g->window.ref, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	}
	else
		mlx_mouse_show();
}
