/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:58:11 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 19:18:23 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	set_value_of_return(t_cmd cmd, int vor)
{
	if (cmd.is_pipe_in == false && cmd.is_pipe_out == false)
		g_struct->value_of_return = vor;
	return (0);
}

void	grab_line_exit(char *str)
{
	write(2, "exit\nbash: exit: ", 17);
	write(2, str, ft_strlen(str));
	write(2, " numeric argument required\n", 27);
	exit (255);
}

int	ft_exit(t_cmd cmd)
{
	int	i;

	i = 1;
	redirect_switch("", cmd);
	while (cmd.args[i] != 0)
	{
		if (check_atoi(cmd.args[i]) != 0)
			grab_line_exit(cmd.args[i]);
		else if (cmd.args[i + 1] != 0)
		{
			write(2, "exit\nbash: exit: too many arguments\n", 36);
			return (set_value_of_return(cmd, 1));
		}
		else
		{
			if (cmd.is_pipe_in == false && cmd.is_pipe_out == false)
				write(1, "exit\n", 5);
			exit(ft_atoi(cmd.args[i]) % 256);
		}
		i++;
	}
	if (cmd.is_pipe_in == false && cmd.is_pipe_out == false)
		write(1, "exit\n", 5);
	exit (g_struct->value_of_return);
}

int	check_atoi(char *str)
{
	int					i;
	unsigned long long	j;
	unsigned long long	old;

	j = 0;
	i = 0;
	old = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] != '\0')
			i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		old = j;
		j = j * 10;
		j += str[i] - '0';
		if (j < old || j > 9223372036854775807)
			return (-1);
		i++;
	}
	return (0);
}
