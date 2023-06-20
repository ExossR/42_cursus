/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:00:58 by jbertin           #+#    #+#             */
/*   Updated: 2023/03/23 16:55:09 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define FOV_ANGLE 66			// field of view angle
# define M_SPEED 0.05			// Movement speed
# define R_SPEED 0.4			// Rotation speed

/* Minimap settings */
# define MMAP_AC 0x00FF6666		// Arrow color
# define MMAP_WC 0x00000099		// Wall color
# define MMAP_SC 0xB4000000		// Shadow color
# define MMAP_FC 0x0099FFFF		// Floor color
# define MMAP_PC 0x00990000		// Player color
# define MMAP_FVC 0x00C8C8C8	// Field view color
# define MMAP_RES 4				// Size in pixel of one case (resolution)

/* Linux Keyboard settings */
// #define LEFT 97
// #define RIGHT 100
// #define DOWN 115
// #define UP 119
// #define RLEFT 65361
// #define RRIGHT 65363
// #define ESCAPE 65307

/* MacOS Keyboard settings */
# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13
# define RLEFT 123
# define RRIGHT 124
# define ESCAPE 53

/*
	Parsing structure
*/
typedef struct s_data
{
	char	**file;
	int		filey;
	char	**map;
	char	**maps;
	char	**map_temp;
	char	*floor_color;
	char	*ceiling_color;
	int		nb_colors;
	int		spawn_point;
	char	spawn_dir;
	int		error;
	int		play_posx;
	int		play_posy;
	int		map_sy;
	int		map_sx;
	char	*no_sprite;
	char	*so_sprite;
	char	*ea_sprite;
	char	*we_sprite;
	int		tmp_nb;
}	t_data;

typedef struct s_drawline {
	int	x0;
	int	y0;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}			t_drawline;

typedef struct s_vector
{
	int		x;
	int		y;
	double	dx;
	double	dy;
	double	dir;
}				t_vector;

typedef struct s_window {
	void		*ref;
	t_vector	size;
}				t_window;

typedef struct s_color {
	int			r;
	int			g;
	int			b;
	int			t;
	int			color;
}				t_color;

/*
	Structure to manage the continuous movement of the player
	as long as the key is pressed
*/
typedef struct s_move {
	bool	left;
	bool	right;
	bool	down;
	bool	up;
	bool	rrot;
	bool	lrot;
}				t_move;

/*
	Structure to handle minilibx images
*/
typedef struct s_image {
	void		*ref;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

/* Raycasting structure, to store data form each ray
raydir(x/y) ->		ray direction (x - horizontal, y - vertical)
deltadist(x/y) ->	distance between two points on the path of the ray
map(x/y) ->			current position of the ray on the map grid
hit ->				a flag indicating whether the ray hit a wall or not
perpwalldist ->		perpendicular distance between player and wall hit by ray
lineheight ->		the height of the wall to be drawn on the screen
step(x/y) ->		direction of jump on the map grid when ray crosses a line
sidedist(x/y) ->	distance between player's pos & intersection point ray
*/
typedef struct s_ray {
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	deltadist_x;
	double	deltadist_y;
	int		mapx;
	int		mapy;
	int		hit;
	double	perpwalldist;
	int		lineheight;
	int		linetrueheight;
	int		stepx;
	int		stepy;
	double	sidedist_x;
	double	sidedist_y;
	int		side;
}				t_ray;

typedef struct s_game {
	t_window	window;
	t_vector	win_s;
	void		*mlx;
	t_image		no_sprite;
	t_image		so_sprite;
	t_image		ea_sprite;
	t_image		we_sprite;
	t_image		player_sprite;
	t_image		player_spritef;
	t_image		hud;
	t_image		munition;
	int			mun;
	t_color		ccolor;
	t_color		fcolor;
	char		**map;
	t_vector	map_s;
	t_move		move;
	t_vector	play;
	t_vector	v_plan;
	t_vector	v_dir;
	t_image		mmap;
	t_image		mmap2;
	t_image		game3d;
	t_image		game3d2;
	int			frame;
	int			frame_anim;
	t_ray		ray;
	t_drawline	line;
	int			fire;
	t_vector	draw_dest;
	int			mouse_lock;
}				t_game;

/* MAIN */
void		ft_exit(t_data *g, int phase);

/* ----- PARSING FUNCTIONS ----- */

/* Ft_check_map_file */
int			ft_is_map_empty(char *input);
int			ft_check_file(char *input);
int			ft_file_size(char *input);
char		**ft_save_file(char *input, t_data *g);

/* Ft_parsing*/
int			ft_parse_map(t_data *game_data);
int			ft_size_map(t_data *g);
void		ft_save_map(t_data *g, int size_map);
void		ft_simplify_map(t_data *g);
char		*ft_adapt_line(char *line, int size);

/* Ft_check_textures */
int			ft_check_texture(t_data *game_data);
int			ft_check_texture_file(char *path);
int			ft_check_textures_arg(t_data *game_data, char *texture);
void		ft_save_texture_color_data(t_data *g);

/* Ft_check_colors */
// Main checking colors function, find the line, check if more than 2 lines
int			ft_check_colors(t_data *game_data, char *color);
// Check the numbers, not less than 0 not more than 255
int			ft_check_color_format(char **color, t_data *g);
// Check if there is more than 2 ',' or letter in arg
int			ft_check_color_arg(char *arg);

/* Ft_is_valid_map -> path finder*/
int			ft_is_valid_map(t_data *g);
int			ft_is_valid_position(t_data *g);
void		ft_path_finding(t_data *g, int y, int x);
void		ft_launch_path_finding(t_data *g);

/* Ft_is_valid_map_tools */
int			ft_check_parasite(t_data *g);
int			ft_valid_maplign(char *arg);
int			ft_valid_maplign2(char *arg);
int			ft_valid_arg(char *arg);
void		ft_find_playerition(t_data *g);

/* Ft_tools */
void		ft_free_splitted(char **str, int size);
void		ft_free_splitted_base(char **str);
void		ft_create_temp_map(t_data *g);
void		ft_create_temp_map2(t_data *g);

/* ----- END PARSING FUNCTIONS ----- */

/* ----- GAME FUNCTIONS ----- */

/* Ft_3drender */
void		ft_draw_3d(t_game *g, t_image *img);

/* Ft_display_game */
int			ft_loop_handler(t_game *g);
t_image		ft_new_sprite(void *mlx, char *path);
t_image		ft_new_image(t_game *g, int x, int y);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);

/* Ft_draw_square */
void		ft_square_blank(t_game *g, t_image *img);
void		ft_square_play(int x, int y, int color, t_image *img);
void		ft_square(int x, int y, int color, t_image *img);

/* Ft_init_game */
t_window	ft_new_window(void *mlx, int widht, int height, char *name);
void		ft_init_game(t_game *game, t_data *data);

/* Ft_init_datas */
void		ft_init_datas(t_game *game);
int			verif_xpm(void *mlx, char *path);

/* Ft_launch_game */
int			ft_close(t_game *game);
void		ft_launch_game(t_data *g);

/* Ft_minimap */
void		ft_draw_minimap(t_game *g, t_image *img);

/* Ft_player_move */
void		ft_move_player(t_game *g);
void		ft_mouse(t_game *g);
int			ft_mouse_click(int click, int x, int y, t_game *g);

/* Ft_raycast */
void		ft_calc_dist_high(t_game *g);
void		ft_check_wall_collision(t_game *g);
void		ft_calc_step_distance(t_game *g);
void		ft_init_ray(t_game *g, int ray_nb);

/* Ft_key_press */
int			key_press_up_down(int keycode, t_game *g);
int			key_press_right_left(int keycode, t_game *g);
int			key_press_rotate(int keycode, t_game *g);
int			comb_key_press(int keycode, t_game *g);
int			ft_key_press_handler(int keycode, t_game *g);

/* Ft_key_release */
int			key_release_up_down(int keycode, t_game *g);
int			key_release_right_left(int keycode, t_game *g);
int			key_release_rotate(int keycode, t_game *g);
int			ft_key_release_handler(int keycode, t_game *g);

/* Ft_display_player */
void		ft_display_hud(t_game *g);
void		ft_player_display(t_game *g, int frame);

/* ----- END GAME FUNCTIONS ----- */

/* Debugging Tools */
void		ft_print_file(t_data *game_data);
void		ft_print_game_data(t_data *game_data);
void		ft_print_game_data2(t_data *game_data);
void		ft_print_all(t_data *g);
void		ft_print_all2(t_game *g);

#endif
