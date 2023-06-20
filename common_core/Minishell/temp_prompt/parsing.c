/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:35:29 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/16 10:28:47 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	fill_cmd(t_cmd *cmd, char *line)
{
	char	**sp;
	int		pos;
	bool	*args_bool_quote;

	pos = 0;
	args_bool_quote = ft_calloc(number_of_word(line), sizeof(bool));
	sp = split_with_quote(line, args_bool_quote);
	cmd->name = fill_name_cmd(*cmd, &pos, sp);
	cmd->args = fill_args_cmd(pos, sp, args_bool_quote);
	cmd->redirect_out = this_redirect(sp, ">", args_bool_quote);
	cmd->redirect_in = this_redirect(sp, "<", args_bool_quote);
	cmd->redirect_append = this_redirect(sp, ">>", args_bool_quote);
	cmd->here_doc = this_redirect(sp, "<<", args_bool_quote);
	cmd->in_last = is_in_last(sp);
	cmd->out_last = is_out_last(sp);
	cmd->is_builtins = is_builtins(sp[pos]);
	free(args_bool_quote);
	free_arr(sp);
}

void	init_cmd(t_cmd *cmd)
{
	cmd->name = 0;
	cmd->args = 0;
	cmd->redirect_out = 0;
	cmd->redirect_in = 0;
	cmd->redirect_append = 0;
	cmd->here_doc = 0;
	cmd->out_last = false;
	cmd->in_last = false;
	cmd->is_pipe_in = false;
	cmd->is_pipe_out = false;
	cmd->is_builtins = false;
}

t_cmd_line	*fill_cmd_line(t_cmd_line *cmd_line, char *line)
{
	int		i;
	int		nb_pipe;
	char	**sp;

	i = 0;
	sp = 0;
	nb_pipe = nb_of_char_valid(line, '|');
	cmd_line->size_of_tab = nb_pipe + 1;
	cmd_line->commands = malloc((cmd_line->size_of_tab) * sizeof(t_cmd));
	sp = ft_split_pipe_quote(line);
	while (sp[i] != 0)
	{
		init_cmd(&(cmd_line->commands[i]));
		if (i > 0)
			cmd_line->commands[i].is_pipe_in = true;
		if (i < nb_pipe)
			cmd_line->commands[i].is_pipe_out = true;
		fill_cmd(&(cmd_line->commands[i]), sp[i]);
		i++;
	}
	free_arr(sp);
	return (cmd_line);
}

t_cmd_line	*parsing(char *line)
{
	t_cmd_line	*cmd_line;
	bool		err;

	err = error_handle(line);
	if (err == true)
	{
		printf("Minishell: syntax error near unexpected token\n");
		return (0);
	}
	cmd_line = malloc(sizeof(t_cmd_line));
	if (!cmd_line)
		return (0);
	cmd_line = fill_cmd_line(cmd_line, line);
	return (cmd_line);
}
