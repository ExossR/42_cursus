/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_datas_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:34:17 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/19 17:48:17 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	verif_xpm(void *mlx, char *path)
{
	t_image	img;
	void	*ref;

	ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	if (ref == 0)
		return (1);
	return (0);
}

void	ft_init_datas(t_game *game)
{
	game->move.down = false;
	game->move.up = false;
	game->move.left = false;
	game->move.right = false;
	game->move.rrot = false;
	game->move.lrot = false;
	game->player_sprite = ft_new_sprite(game->mlx, "sprites/player.xpm");
	game->player_spritef = ft_new_sprite(game->mlx, "sprites/player-fire.xpm");
	game->hud = ft_new_sprite(game->mlx, "sprites/hud.xpm");
	game->munition = ft_new_sprite(game->mlx, "sprites/mun.xpm");
	game->mmap = ft_new_image(game, (game->map_s.x + 1) * MMAP_RES,
			(game->map_s.y + 1) * MMAP_RES);
	game->mmap2 = ft_new_image(game, (game->map_s.x + 1) * MMAP_RES,
			(game->map_s.y + 1) * MMAP_RES);
	game->game3d = ft_new_image(game, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->game3d2 = ft_new_image(game, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->frame = 0;
	game->frame_anim = 0;
}
