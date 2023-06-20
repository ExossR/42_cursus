/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:15:24 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/16 19:12:40 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Calculate the current ray direction and the step size
// Initialize others datas
void	ft_init_ray(t_game *g, int ray_nb)
{
	g->ray.camera_x = (2 * ray_nb / (double)SCREEN_WIDTH) - 1;
	g->ray.raydir_x = g->v_dir.dx + g->v_plan.dx * g->ray.camera_x;
	g->ray.raydir_y = g->v_dir.dy + g->v_plan.dy * g->ray.camera_x;
	g->ray.deltadist_x = fabs(1 / g->ray.raydir_x);
	g->ray.deltadist_y = fabs(1 / g->ray.raydir_y);
	g->ray.mapx = (int)g->play.dx;
	g->ray.mapy = (int)g->play.dy;
	g->ray.hit = 0;
	g->ray.perpwalldist = 0;
	g->ray.lineheight = 0;
	g->ray.linetrueheight = 0;
	g->ray.stepx = 0;
	g->ray.stepy = 0;
	g->ray.sidedist_x = 0;
	g->ray.sidedist_y = 0;
	g->ray.side = 0;
}

// Calculate the initial step and the side distance
void	ft_calc_step_distance(t_game *g)
{
	if (g->ray.raydir_x < 0)
	{
		g->ray.stepx = -1;
		g->ray.sidedist_x = (g->play.dx - g->ray.mapx) * g->ray.deltadist_x;
	}
	else
	{
		g->ray.stepx = 1;
		g->ray.sidedist_x = (g->ray.mapx + 1.0 - g->play.dx)
			* g->ray.deltadist_x;
	}
	if (g->ray.raydir_y < 0)
	{
		g->ray.stepy = -1;
		g->ray.sidedist_y = (g->play.dy - g->ray.mapy) * g->ray.deltadist_y;
	}
	else
	{
		g->ray.stepy = 1;
		g->ray.sidedist_y = (g->ray.mapy + 1.0 - g->play.dy)
			* g->ray.deltadist_y;
	}
}

// Loop through the map until a wall is hit
// Jump to the next map square
// Check if the ray has hit a wall
void	ft_check_wall_collision(t_game *g)
{
	g->ray.hit = 0;
	g->ray.side = 0;
	while (!g->ray.hit)
	{
		if (g->ray.sidedist_x < g->ray.sidedist_y)
		{
			g->ray.sidedist_x += g->ray.deltadist_x;
			g->ray.mapx += g->ray.stepx;
			g->ray.side = 0;
		}
		else
		{
			g->ray.sidedist_y += g->ray.deltadist_y;
			g->ray.mapy += g->ray.stepy;
			g->ray.side = 1;
		}
		if (g->map[g->ray.mapy][g->ray.mapx] == '1')
			g->ray.hit = 1;
	}
}

// Calculate the perpendicular distance to the wall
// Calculate the height of the wall on the screen
void	ft_calc_dist_high(t_game *g)
{
	if (g->ray.side == 0)
		g->ray.perpwalldist = (g->ray.sidedist_x - g->ray.deltadist_x);
	else
		g->ray.perpwalldist = (g->ray.sidedist_y - g->ray.deltadist_y);
	g->ray.lineheight = (int)(SCREEN_HEIGHT / g->ray.perpwalldist);
	if (g->ray.lineheight > SCREEN_HEIGHT)
	{
		g->ray.linetrueheight = g->ray.lineheight;
		g->ray.lineheight = SCREEN_HEIGHT - 1;
	}
}
