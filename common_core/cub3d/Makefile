UP = "\033[A"
CLEAR = "\033[K"

NAME = cub3D
SRCS = 	srcs/main.c \
		srcs/ft_check_map_file.c \
		srcs/ft_parsing.c \
		srcs/ft_tools.c \
		srcs/ft_check_textures.c \
		srcs/ft_is_valid_map.c \
		srcs/ft_check_colors.c \
		srcs/ft_is_valid_map_tools.c \
		srcs/ft_debug.c \
		srcs/ft_launch_game.c \
		srcs/ft_init_game.c \
		srcs/ft_display.c \
		srcs/ft_player_move.c \
		srcs/ft_minimap.c \
		srcs/ft_3drender.c \
		srcs/ft_draw_square.c \
		srcs/ft_key_press.c \
		srcs/ft_key_release.c \
		srcs/ft_display_player.c \
		srcs/ft_init_datas.c \
		srcs/ft_raycast.c

SRCS_BONUS = 	srcs/main_bonus.c \
		srcs/ft_check_map_file_bonus.c \
		srcs/ft_parsing_bonus.c \
		srcs/ft_tools_bonus.c \
		srcs/ft_check_textures_bonus.c \
		srcs/ft_is_valid_map_bonus.c \
		srcs/ft_check_colors_bonus.c \
		srcs/ft_is_valid_map_tools_bonus.c \
		srcs/ft_debug_bonus.c \
		srcs/ft_launch_game_bonus.c \
		srcs/ft_init_game_bonus.c \
		srcs/ft_display_bonus.c \
		srcs/ft_player_move_bonus.c \
		srcs/ft_minimap_bonus.c \
		srcs/ft_3drender_bonus.c \
		srcs/ft_draw_square_bonus.c \
		srcs/ft_key_press_bonus.c \
		srcs/ft_key_release_bonus.c \
		srcs/ft_display_player_bonus.c \
		srcs/ft_init_datas_bonus.c \
		srcs/ft_raycast_bonus.c

LIBFT_A = libft.a
LIBF_DIR = libft/

# MacOS Minilibx
MINILIBX_A = libmlx.a
LIBMLX_DIR = minilibx/

LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))
MINILIBX  = $(addprefix $(LIBMLX_DIR), $(MINILIBX_A))

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

INCLUDE = -framework OpenGL -framework AppKit

ifdef WITH_BONUS
	OBJS = $(SRCS_BONUS:.c=.o)
endif

all: $(NAME)

.c.o:
	@gcc $(FLAGS) -c $< -o $(<:.c=.o)
	@echo $(UP)$(CLEAR)"\033[0;93mCompiling Cub3D : $@ \033[0;39m"

$(NAME): $(OBJS)
	@make -C $(LIBF_DIR)
	@make -C $(LIBMLX_DIR)
	@gcc $(FLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(INCLUDE) -o $(NAME) $(MINILIBX)
	clear
	@cat .msg
	@echo $(CLEAR)"\033[0;92mCub3D compiled !\033[0;39m"

bonus:
	@make WITH_BONUS=1

clean:
	@make -C $(LIBF_DIR) clean
	@make -C $(LIBMLX_DIR) clean
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)
	@echo $(UP)$(CLEAR)"\033[0;92mCub3D cleaned !\033[0;39m"

fclean: clean
	@make -C $(LIBF_DIR) fclean
	@rm -rf $(NAME)

re: fclean all
