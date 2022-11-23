SRCS = srcs/ft_printf.c srcs/ft_printf_utils.c srcs/ft_putchar_fd.c srcs/ft_putnbr_fd.c srcs/ft_strlen.c
BNS = 
OBJS = $(SRCS:.c=.o)
OBJBNS = $(BNS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(OBJBNS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(OBJBNS)
	ar cr $(NAME) $(OBJS) $(OBJBNS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I includes/ -c $< -o $(<:.c=.o)
