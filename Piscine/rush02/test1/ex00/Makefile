MY_SOURCES = srcs/main.c			\
			 srcs/display.c			\
			 srcs/ft_function2.c	\
			 srcs/ft_functions.c	\
			 srcs/functions_split.c	\
			 srcs/parsing.c			\
			 srcs/split_string.c	\
			 srcs/ft_function3.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

NAME = rush-02

MY_HEADERS = includes/

FLAGS = -Wall -Wextra -Werror -I $(MY_HEADERS)

all: $(NAME)

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(MY_OBJECTS)
	gcc $(MY_HEADER) $(MY_OBJECTS) -o $(NAME)

clean:
	rm -f $(MY_SOURCES:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all
