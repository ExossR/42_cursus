SOURCE_FILES = ft_atoi.c \
			   ft_bzero.c \
			   ft_calloc.c \
			   ft_isalnum.c \
			   ft_isalpha.c \
			   ft_isascii.c \
			   ft_isdigit.c \
			   ft_isprint.c \
			   ft_itoa.c \
			   ft_memchr.c \
			   ft_memcmp.c \
			   ft_memcpy.c \
			   ft_memmove.c \
			   ft_memset.c \
			   ft_putchar_fd.c \
			   ft_putendl_fd.c \
			   ft_putnbr_fd.c \
			   ft_putstr_fd.c \
			   ft_split.c \
			   ft_strchr.c \
			   ft_strdup.c \
			   ft_striteri.c \
			   ft_strjoin.c \
			   ft_strlcat.c \
			   ft_strlcpy.c \
			   ft_strlen.c \
			   ft_strmapi.c \
			   ft_strncmp.c \
			   ft_strnstr.c \
			   ft_strrchr.c \
			   ft_strtrim.c \
			   ft_substr.c \
			   ft_tolower.c \
			   ft_toupper.c \
			   get_next_line.c \
			   get_next_line_utils.c \

BONUS_SOURCE_FILES = 	ft_lstadd_front.c \
						ft_lstdelone.c \
						ft_lstclear.c \
               		 	ft_lstlast.c \
               		 	ft_lstnew.c \
               		 	ft_lstsize.c \
						ft_lstadd_back.c \
						ft_lstiter.c \
						ft_lstmap.c

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

BONUS_OBJECT_FILES = $(BONUS_SOURCE_FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: libft.a

.c.o:
	gcc $(CFLAGS) -c $< -o $(<:.c=.o)

libft.a: $(OBJECT_FILES)
	ar rcs ../../libft.a $(OBJECT_FILES)

re: fclean all

fclean: clean
	rm -f libft.a

clean:
	rm -f $(SOURCE_FILES:.c=.o)
	rm -f $(BONUS_SOURCE_FILES:.c=.o)

bonus: $(OBJECT_FILES) $(BONUS_OBJECT_FILES)
	ar rcs libft.a $(OBJECT_FILES) $(BONUS_OBJECT_FILES)

