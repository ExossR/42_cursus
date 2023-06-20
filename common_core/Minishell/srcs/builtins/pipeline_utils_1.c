/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:28:44 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 19:19:41 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	check_builtins_solo(t_cmd_line cmd_line)
{
	if (cmd_line.commands[0].name == 0)
		return (1);
	if (cmd_line.size_of_tab == 1
		&& double_check(cmd_line.commands[0].name, "exit"))
		return (gl_builtins_solo(cmd_line.commands[0]));
	if (cmd_line.size_of_tab == 1
		&& double_check(cmd_line.commands[0].name, "unset"))
		return (gl_builtins_solo(cmd_line.commands[0]));
	if (cmd_line.size_of_tab == 1
		&& double_check(cmd_line.commands[0].name, "export"))
		return (gl_builtins_solo(cmd_line.commands[0]));
	else if (cmd_line.size_of_tab == 1
		&& double_check(cmd_line.commands[0].name, "cd"))
		return (gl_builtins_solo(cmd_line.commands[0]));
	else
		return (1);
}

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != 0)
	{
		ft_putstr_fd(env[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
}

void	throw_error_execve(char *str)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

void	replace_stds(bool a, t_cmd cmd)
{
	int	rt;

	if (a == true)
	{
		rt = replace_stdin(cmd);
		if (rt != 0)
			exit(rt);
	}
	else if (a == false)
	{
		rt = replace_stdout(cmd);
		if (rt != 0)
			exit(rt);
	}
}

int	ft_execve(t_cmd cmd, int *pipe, int tmp_fd)
{
	if (cmd.redirect_in != 0 || cmd.here_doc != 0)
		replace_stds(true, cmd);
	else if (cmd.is_pipe_in == true)
		dup2(tmp_fd, 0);
	if (cmd.redirect_out != 0 || cmd.redirect_append != 0)
		replace_stds(false, cmd);
	else if (cmd.is_pipe_out == true)
		dup2(pipe[1], 1);
	if (tmp_fd != 0)
		close(tmp_fd);
	close(pipe[0]);
	close(pipe[1]);
	if (cmd.name == 0)
		return (0);
	if (cmd.is_builtins == true)
		builtins_switch(cmd.name, cmd);
	else if (execve(cmd.name, cmd.args, g_struct->g_env) == -1)
		throw_error_execve(cmd.name);
	return (0);
}
