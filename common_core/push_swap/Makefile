SRCS = 	srcs/ft_split.c \
		srcs/main.c \
		srcs/main_utils.c \
		srcs/main_utils_2.c \
		srcs/sort.c \
		srcs/sort_utils.c \
		srcs/swap.c \
		srcs/swap_utils.c \
		srcs/swap_sort_small.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJBNS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(FLAGS) -I includes/ -c $< -o $(<:.c=.o)
