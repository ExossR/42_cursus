SRCS = Contact.cpp PhoneBook.cpp main.cpp
NAME = phonebook

OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

.c.o:
	c++ $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)

re: fclean all
