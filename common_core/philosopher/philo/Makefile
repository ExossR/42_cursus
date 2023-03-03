SRCS = 	srcs/main.c \
		srcs/main_utils.c \
		srcs/ft_atoi.c \
		srcs/exec_philo.c \
		srcs/init.c \
		srcs/thread.c \
		srcs/thread_utils.c \
		srcs/free.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror 
NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -g -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJBNS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(FLAGS) -I includes/ -c $< -o $(<:.c=.o)
