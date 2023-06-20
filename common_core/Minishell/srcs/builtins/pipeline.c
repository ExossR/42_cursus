/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:28:44 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 19:20:18 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	gl_start_pipeline(t_pip_struct *a)
{
	g_struct->is_in_cmd = true;
	a->i = 0;
	a->tmp_fd = 0;
	set_termios(true);
}

void	gl_end_pipeline(t_pip_struct *a)
{
	if (a->tmp_fd != 0)
		close(a->tmp_fd);
	a->pids[1] = waitpid(-1, &a->status, 0);
	while (a->pids[1] > 0)
	{
		if (WIFSIGNALED(a->status) && a->pids[1] == a->pids[0])
		{
			if (WTERMSIG(a->status) == SIGSEGV)
				write (2, "Segmentation fault: 11\n", 23);
			else if (WTERMSIG(a->status) == SIGBUS)
				write (2, "Bus error\n", 10);
			g_struct->value_of_return = WTERMSIG(a->status) + 128;
		}
		if (WIFEXITED(a->status) && a->pids[1] == a->pids[0])
			g_struct->value_of_return = (WEXITSTATUS(a->status));
		a->pids[1] = waitpid(-1, &a->status, 0);
	}
	set_termios(false);
	g_struct->is_in_cmd = false;
	free(a);
}

void	gl_mid_pipeline(t_pip_struct *a, t_cmd_line *cmd_line)
{
	if (a->pids[0] > 0 && cmd_line->commands[a->i].here_doc != 0)
		g_struct->pid_here_doc = a->pids[0];
	if (a->pids[0] == 0)
		ft_execve(cmd_line->commands[a->i], a->pipe_fd, a->tmp_fd);
	if (a->tmp_fd != 0)
		close(a->tmp_fd);
}

int	pipeline(t_cmd_line *cmd_line)
{
	t_pip_struct	*a;

	a = malloc(sizeof(t_pip_struct));
	gl_start_pipeline(a);
	while (a->i < cmd_line->size_of_tab)
	{
		if (pipe(a->pipe_fd) == -1)
			return (call_error());
		if (check_builtins_solo(*cmd_line) != 0)
		{
			a->pids[0] = fork();
			if (a->pids[0] < 0)
			{
				call_error();
				close(a->pipe_fd[1]);
				break ;
			}
			gl_mid_pipeline(a, cmd_line);
			close(a->pipe_fd[1]);
			a->tmp_fd = a->pipe_fd[0];
		}
		a->i++;
	}
	gl_end_pipeline(a);
	return (0);
}

int	gl_builtins_solo(t_cmd cmd)
{
	builtins_switch(cmd.name, cmd);
	return (0);
}
