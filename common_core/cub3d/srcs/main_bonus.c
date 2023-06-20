/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:31:30 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/19 17:48:49 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_exit(t_data *g, int phase)
{
	if (phase == 4)
		ft_free_splitted(g->maps, g->map_sy);
	if (phase == 4 || phase == 3)
	{
		free(g->no_sprite);
		free(g->so_sprite);
		free(g->we_sprite);
		free(g->ea_sprite);
		free(g->floor_color);
		free(g->ceiling_color);
	}
}

int	main(int ac, char **av)
{
	t_data	*game_data;

	if (ac != 2)
	{
		printf("Error.\nWrong number of arguments, should be 2.\n");
		return (1);
	}
	else if (!ft_check_file(av[1]) || !ft_is_map_empty(av[1]))
		return (1);
	else
	{
		game_data = malloc(sizeof(t_data) * 1);
		if (!game_data)
			return (1);
		game_data->file = ft_save_file(av[1], game_data);
		ft_parse_map(game_data);
		ft_free_splitted(game_data->file, game_data->filey);
		free(game_data);
	}
	return (0);
}
