SOURCE_FILES = srcs/builtins/builtins.c \
			   srcs/builtins/builtins_utils.c \
			   srcs/builtins/cd.c \
			   srcs/builtins/echo.c \
			   srcs/builtins/env.c \
			   srcs/builtins/env_var.c \
			   srcs/builtins/exit.c \
			   srcs/builtins/export.c \
			   srcs/builtins/export_utils_1.c \
			   srcs/builtins/export_utils_2.c \
			   srcs/builtins/here_doc.c \
			   srcs/builtins/pipeline.c \
			   srcs/builtins/pipeline_utils_1.c \
			   srcs/builtins/pipeline_utils_2.c \
			   srcs/builtins/pwd.c \
			   srcs/builtins/redirect.c \
			   srcs/builtins/unset.c \
			   temp_prompt/free.c \
			   temp_prompt/last.c \
			   temp_prompt/main.c \
			   temp_prompt/main_utils_2.c \
			   temp_prompt/main_utils.c \
			   temp_prompt/parsing.c \
			   temp_prompt/parsing_args.c \
			   temp_prompt/parsing_args_utils.c \
			   temp_prompt/parsing_args_utils_2.c \
			   temp_prompt/parsing_args_utils_3.c \
			   temp_prompt/parsing_syntaxe.c \
			   temp_prompt/parsing_syntaxe_utils.c \
			   temp_prompt/parsing_syntaxe_utils_2.c \
			   temp_prompt/parsing_syntaxe_tokens.c \
			   temp_prompt/lst_token.c \
			   temp_prompt/split_quote.c \
			   temp_prompt/split_quote_utils.c \
			   temp_prompt/split_quote_utils_2.c \
			   temp_prompt/split_quote_utils_3.c \
			   temp_prompt/this_redirect.c \
			   temp_prompt/signal.c \

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

all: lib minishell

lib:
	make -C ./srcs/libft

.c.o:
	gcc $(CFLAGS) -I./includes -g -c $< -o $(<:.c=.o)

minishell: $(OBJECT_FILES)
	gcc $(OBJECT_FILES) libft.a -o minishell -lreadline -L ~/.brew/opt/readline/lib

re: fclean all

fclean: clean
	make fclean -C ./srcs/libft
	rm -f minishell

clean:
	make clean -C ./srcs/libft
	rm -f $(SOURCE_FILES:.c=.o)
