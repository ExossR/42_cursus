# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asahonet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 16:11:04 by asahonet          #+#    #+#              #
#    Updated: 2022/10/04 21:51:49 by asahonet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c srcs/display.c srcs/board.c srcs/parsing.c srcs/solve.c srcs/sub_functions_parsing.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Werror -Wall -Wextra
NAME = bsq

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I includes -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) -I includes/ $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
