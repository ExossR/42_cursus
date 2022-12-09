/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:52:30 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/06 11:01:44 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	verif_arg(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (argv[1][ft_strlen(argv[1]) - 1] != 'f'
		|| argv[1][ft_strlen(argv[1]) - 2] != 'd'
		|| argv[1][ft_strlen(argv[1]) - 3] != 'f'
		|| argv[1][ft_strlen(argv[1]) - 4] != '.')
		return (0);
	if (open(argv[1], O_RDONLY) == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;

	if (verif_arg(argc, argv) == 0)
		return (0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, W_WIDTH, W_HEIGHT, "Fdf - Fil de fer");
	img.img = mlx_new_image(vars.mlx, W_WIDTH, W_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	vars.map = init_map_read(argv[1]);
	convert_map(vars.map);
	print_all_lines(vars.map, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 17, 0L, hook_exit, &vars);
	mlx_hook(vars.win, 02, 1L << 0, close_win, &vars);
	mlx_loop(vars.mlx);
}
