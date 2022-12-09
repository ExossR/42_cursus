/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:12:21 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/06 15:27:13 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define W_WIDTH	1920
# define W_HEIGHT	1080
# define M_X		1820
# define M_Y		780
# define O_X		960
# define O_Y		15

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_point	**map;
}	t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int		find_n_value(char *str, int n);
void	set_coordonate(t_point *point, int x, int y, int z);
int		map_arg_y(char *file_name);
int		map_arg_x(char *file_name);
int		max(int a, int b);
int		count_y(t_point **map);
int		count_x(t_point **map);
void	draw_line(t_data *mlx, t_point a, t_point b);
void	put_pixel(t_point point, t_data img);
void	convert_map(t_point **map);
t_point	**init_map_read(char *file_name);
void	print_all_lines(t_point **map, t_data *mlx);
int		close_win(int keycode, t_vars *vars);
int		hook_exit(t_vars *vars);

#endif