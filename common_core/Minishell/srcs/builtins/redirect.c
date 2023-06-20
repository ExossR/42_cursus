/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:09:57 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 09:32:37 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	redirect_switch(char *str, t_cmd cmd)
{
	if (cmd.redirect_out != 0 || cmd.redirect_append != 0)
	{
		if (cmd.redirect_out != 0)
			redirect_out(str, cmd);
		if (cmd.redirect_append != 0)
			redirect_append(str, cmd);
	}
	else
		ft_putstr_fd(str, 1);
}

void	redirect_out(char *str, t_cmd cmd)
{
	int	i;
	int	fd;

	i = 0;
	while (cmd.redirect_out[i] != 0)
	{
		fd = open(cmd.redirect_out[i], O_WRONLY
				| O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (fd == -1)
			break ;
		if (cmd.redirect_out[i + 1] == 0 && cmd.out_last == 0)
			ft_putstr_fd(str, fd);
		close(fd);
		i++;
	}
}

void	redirect_append(char *str, t_cmd cmd)
{
	int	i;
	int	fd;

	i = 0;
	while (cmd.redirect_append[i] != 0)
	{
		fd = open(cmd.redirect_append[i], O_WRONLY
				| O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (fd == -1)
			break ;
		if (cmd.redirect_append[i + 1] == 0 && cmd.out_last == 1)
			ft_putstr_fd(str, fd);
		close(fd);
		i++;
	}
}
