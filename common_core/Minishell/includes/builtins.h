/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:07:49 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 19:16:18 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "libft.h"
# include <stdio.h>
# include <errno.h>
# include <signal.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

/*-----------Var Globale-----------*/
typedef struct s_gstruct {
	int		value_of_return;
	bool	is_in_cmd;
	char	**g_env;
	pid_t	pid_here_doc;
	bool	is_in_here_doc;
	bool	*is_in_env;
}	t_struct;

t_struct	*g_struct;

/*-----------struct-----------*/
typedef struct s_cmd {
	char	*name;
	char	**args;
	char	**redirect_out;
	char	**redirect_in;
	char	**here_doc;
	char	**redirect_append;
	bool	out_last;
	bool	in_last;
	bool	is_pipe_in;
	bool	is_pipe_out;
	bool	is_builtins;
}	t_cmd;

typedef struct s_cmd_line {
	t_cmd	*commands;
	int		size_of_tab;
}	t_cmd_line;

typedef struct s_type_token
{
	char				token;
	int					nb_in_str_valid;
	int					pos;
	struct s_type_token	*next;
}	t_type_token;

typedef struct s_split_quote {
	char	**tab;
	int		i;
	int		j;
	char	*buff;
	bool	is_in;
	char	which_is_in;
}	t_squote;

typedef struct s_cd_struct {
	char	buffer[2048];
	char	old_buffer[2048];
	int		pos;
	int		home;
	int		old_pwd;
}	t_cd_struct;

typedef struct s_pipeline_struct {
	int		pipe_fd[2];
	int		tmp_fd;
	int		i;
	int		status;
	pid_t	pids[2];
}	t_pip_struct;

void			rl_replace_line(const char *text, int clear_undo);

/*-----------signal.c-----------*/
void			handle_sigint(int signum);
void			handle_sigquit(int signum);
void			set_termios(bool in_cmd);

/*-----------env.c-----------*/
void			tf_split_env(char **tab);
int				env(t_cmd cmd);

/*-----------echo.c-----------*/
int				echo_read(t_cmd cmd, int *n_option);
int				check_option(char *str);
int				echo(t_cmd cmd);

/*-----------builtins_utils.c-----------*/
t_cmd			*init_t_cmd(void);
char			*tf_split(char **tab);
int				call_error(void);

/*-----------exit.c-----------*/
int				ft_exit(t_cmd cmd);
int				check_atoi(char *str);

/*-----------cd.c-----------*/
int				cd(t_cmd cmd);
int				search_in_env(char **env, char *var);
int				exit_or_return(t_cmd cmd, int error);

/*-----------pwd.c-----------*/
int				pwd(t_cmd cmd);

/*-----------export.c-----------*/
int				free_env(char **env);
int				size_of_env(char **env);
int				copy_env(char **env_old, char **new_env);
int				check_env_var(char *str, char **env);
int				find_equal(char *str);
int				ft_export(t_cmd cmd);
bool			is_in_tab_e(char *str);
void			ft_sort_string_tab(char **tab);
void			add_to_env_tab(bool in_env, t_cmd cmd, int i);
/*-----------unset.c-----------*/
int				copy_and_remove(char **env_old, char **new_env, char *target);
int				check_env_var_unset(char *str, char **env);
int				unset(t_cmd cmd);

/*-----------redirect.c-----------*/
void			redirect_switch(char *str, t_cmd cmd);
void			redirect_out(char *str, t_cmd cmd);
void			redirect_append(char *str, t_cmd cmd);

/*-----------pipeline.c-----------*/
int				pipeline(t_cmd_line *cmd_line);
int				ft_execve(t_cmd cmd, int *pipe, int tmp_fd);
int				replace_stdout(t_cmd cmd);
int				replace_stdin(t_cmd cmd);
int				check_builtins_solo(t_cmd_line cmd_line);
void			print_env(char **env);
int				gl_builtins_solo(t_cmd cmd);
/*-----------here_doc.c-----------*/
int				here_doc(t_cmd cmd);

/*-----------builtins.c-----------*/
void			builtins_switch(char *name, t_cmd cmd);
bool			double_check(char *a, char *b);

/*-----------free.c-----------*/
void			free_cmd_line(t_cmd_line *cmd_line);

/*-----------last.c-----------*/
bool			is_out_last(char **sp);
bool			is_in_last(char **sp);

/*-----------main.c-----------*/
void			init_termios(void);
bool			line_is_empty(char *str);
void			alloc_global(char **env);

/*-----------main_utils.c-----------*/
char			**get_tot_env(char **env);

/*-----------this_redirect.c-----------*/
int				length_of_tab(char **tab);
int				find_in_tab(char **tab, char *target, bool *is_quote);
bool			is_token(char *str);
char			**this_redirect(char **tab, char *target, bool *args_bool);

/*-----------parsing.c-----------*/
t_cmd_line		*parsing(char *line);

/*-----------parsing_args.c-----------*/
char			*fill_name_cmd(t_cmd cmd, int *pos, char **sp);
char			**fill_args_cmd(int pos, char **sp, bool *args_bool);
char			*transform_line(char **env, char *line);

/*-----------parsing_args_utils.c-----------*/
char			*find_path_cmd(char **env, char *cmd);
int				is_builtins(char *name);
void			free_arr(char **arr);
char			*search_var_env(char **env, char *line);
int				size_env(char **env);
char			*verif_path_cmd(char **paths, char *cmd_part);

/*-----------parsing_args_utils_2.c-----------*/
int				size_var_env(char *env);
char			*transforming_line(char *line, char *val_var);

/*-----------parsing_syntaxe.c-----------*/
bool			error_handle(char *line);

/*-----------parsing_syntaxe_utils.c-----------*/
bool			begin_is_empty(char *line, char token);
bool			end_is_empty(char *line, int pos);
bool			inter_is_empty(char *line, int pos, char token);
bool			is_space(char c);
int				nb_of_char_valid(char *line, char token);

/*-----------parsing_syntaxe_utils_2.c-----------*/
int				add_count_number_quote(char token, char c);

/*-----------parsing_syntaxe_tokens.c-----------*/
bool			token_pipe(t_type_token *lst, char *line);
bool			token_chevron_right(t_type_token *lst, char *line);
bool			token_chevron_left(t_type_token *lst, char *line);
bool			token_quote(t_type_token *lst);

/*-----------split_quote.c-----------*/
char			**split_with_quote(char *s, bool *output_bool);
char			**ft_split_pipe_quote(char *s);

/*-----------split_quote_utils.c-----------*/
void			handle_redirect(t_squote *output, char *s);
void			handle_quote(t_squote *output, char *s, bool *output_bool);
void			add_to_tab(t_squote *output);
char			*ft_strcat_only_one(char *str, char c);
int				number_of_word(char *str);

/*-----------split_quote_utils_2.c-----------*/
int				next_word(char	*str, char del);
t_squote		*init_split_quote(void);
int				nb_word_pipe(char *s);
int				is_charset(char s);

/*-----------lst_token.c-----------*/
t_type_token	*ft_lstnew_token(char *s, char token, int pos);
void			ft_lstadd_back_token(t_type_token **lst, t_type_token *new);
int				ft_lstsize_token(t_type_token *lst);
void			ft_lstclear_token(t_type_token **lst);

#endif
