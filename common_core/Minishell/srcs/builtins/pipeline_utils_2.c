/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:28:44 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 19:19:56 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	grab_line_replace_stdout(char *str)
{
	write(2, "bash: ", 6);
	ft_putstr_fd(str, 2);
	write(2, ": ", 2);
	return (call_error());
}

int	replace_stdout(t_cmd cmd)
{
	int	i;
	int	fd;

	i = 0;
	redirect_switch("", cmd);
	if (cmd.out_last == false)
	{
		while (cmd.redirect_out[i] != 0)
		{
			if (access(cmd.redirect_out[i], W_OK) != 0)
				return (grab_line_replace_stdout(cmd.redirect_out[i]));
			i++;
		}
		i--;
		fd = open(cmd.redirect_out[i], O_WRONLY | O_TRUNC);
		dup2(fd, 1);
	}
	else
	{
		while (cmd.redirect_append[i + 1] != 0)
			i++;
		fd = open(cmd.redirect_append[i], O_WRONLY | O_APPEND);
		dup2(fd, 1);
	}
	return (0);
}

void	grab_end_line_stdin(t_cmd cmd)
{
	int	fd;

	fd = 0;
	g_struct->is_in_here_doc = true;
	fd = here_doc(cmd);
	dup2(fd, 0);
	g_struct->is_in_here_doc = false;
}

int	replace_stdin(t_cmd cmd)
{
	int	i;
	int	fd;

	i = 0;
	if (cmd.in_last == false)
	{
		while (cmd.redirect_in[i] != 0)
		{
			if (access(cmd.redirect_in[i], R_OK) != 0)
				return (grab_line_replace_stdout(cmd.redirect_in[i]));
			i++;
		}
		i--;
		fd = open(cmd.redirect_in[i], O_RDONLY);
		dup2(fd, 0);
	}
	else
		grab_end_line_stdin(cmd);
	return (0);
}
