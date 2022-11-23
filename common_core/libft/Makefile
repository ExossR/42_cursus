SRCS = ft_atoi.c ft_bzero.c ft_putchar_fd.c ft_strlcpy.c ft_putendl_fd.c ft_strlen.c ft_calloc.c ft_putnbr_fd.c ft_strmapi.c ft_isalnum.c ft_putstr_fd.c ft_strncmp.c ft_isalpha.c ft_split.c ft_strnstr.c ft_isascii.c ft_memchr.c ft_strchr.c ft_strrchr.c ft_isdigit.c ft_memcmp.c ft_strdup.c ft_strtrim.c ft_isprint.c ft_memcpy.c ft_striteri.c ft_substr.c ft_itoa.c ft_memmove.c ft_strjoin.c ft_tolower.c ft_memset.c ft_strlcat.c ft_toupper.c
BNS = ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c ft_lstclear.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstiter.c ft_lstmap.c
OBJS = $(SRCS:.c=.o)
OBJBNS = $(BNS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a

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
