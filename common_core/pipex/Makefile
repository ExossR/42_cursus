SRCS = 	srcs/main.c \
		srcs/main_utils.c \
		srcs/main_utils_2.c \
		srcs/ft_split.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = pipex

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
