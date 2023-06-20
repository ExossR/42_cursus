/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_player_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:24:56 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/19 17:48:10 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_display_hud(t_game *g)
{
	int	mun_posx;
	int	mun_posy;
	int	munitions;

	mun_posx = 20;
	mun_posy = SCREEN_HEIGHT - 50;
	munitions = 0;
	mlx_put_image_to_window(g->mlx, g->window.ref, g->hud.ref, 10,
		SCREEN_HEIGHT - g->hud.size.y - 20);
	while (munitions < g->mun)
	{
		mlx_put_image_to_window(g->mlx, g->window.ref, g->munition.ref,
			mun_posx, mun_posy);
		mun_posx += 7;
		munitions++;
	}
}

static void	ft_player_display_n(t_game *g, int frame, int pos_player)
{
	if (g->frame_anim == 0)
		mlx_put_image_to_window(g->mlx, g->window.ref,
			g->player_sprite.ref, SCREEN_WIDTH / 2, pos_player + frame);
	else
		mlx_put_image_to_window(g->mlx, g->window.ref,
			g->player_sprite.ref, SCREEN_WIDTH / 2, pos_player + 48 - frame);
}

static void	ft_player_display_f(t_game *g, int frame, int pos_player)
{
	if (g->frame_anim == 0)
		mlx_put_image_to_window(g->mlx, g->window.ref,
			g->player_spritef.ref, SCREEN_WIDTH / 2, pos_player + frame);
	else
		mlx_put_image_to_window(g->mlx, g->window.ref,
			g->player_spritef.ref, SCREEN_WIDTH / 2, pos_player + 48 - frame);
}

void	ft_player_display(t_game *g, int frame)
{
	int	pos_player;

	pos_player = SCREEN_HEIGHT - g->player_sprite.size.y;
	if (g->frame < 24)
		g->frame_anim = 0;
	else
		g->frame_anim = 1;
	if (g->fire == 0)
		ft_player_display_n(g, frame, pos_player);
	else
	{
		ft_player_display_f(g, frame, pos_player);
		g->fire = 0;
	}
}
