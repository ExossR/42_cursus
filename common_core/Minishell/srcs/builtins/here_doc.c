/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:01:53 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 18:11:27 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	here_doc(t_cmd cmd)
{
	char	*str;
	int		pipe_fd[2];
	bool	is_finished;

	if (pipe(pipe_fd) == -1)
		return (call_error());
	is_finished = false;
	while (is_finished != true)
	{
		write(1, "> ", 2);
		str = get_next_line(0);
		if (ft_strncmp(str, cmd.here_doc[0], ft_strlen(str) - 1) == 0
			&& ft_strncmp(str,
				cmd.here_doc[0], ft_strlen(cmd.here_doc[0])) == 0)
			is_finished = true;
		else
			write(pipe_fd[1], str, ft_strlen(str));
		free(str);
	}
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}
