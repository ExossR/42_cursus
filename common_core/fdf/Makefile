SRCS = 	srcs/main.c \
		srcs/parsing.c \
		srcs/parsing_utils.c \
		srcs/print_win.c \
		srcs/scale_win.c \
		srcs/scale_win_utils.c \
		srcs/event.c
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fdf

all: lib $(NAME)

lib:
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(OBJS) libft.a -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS) $(OBJBNS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(FLAGS) -Imlx/ -Iincludes/ -Ilibft/ -c $< -o $(<:.c=.o)
