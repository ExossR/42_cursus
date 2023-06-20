/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:59:16 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 18:11:12 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	grab_line_echo(int *counter, t_cmd cmd, char *buffer)
{
	counter[1] = 0;
	while (cmd.args[counter[0]][counter[1]] != '\0')
	{
		if (ft_strlen(buffer) == 0 && check_option(cmd.args[counter[0]]) != 0)
			break ;
		buffer[counter[2]++] = cmd.args[counter[0]][counter[1]++];
	}
	if (ft_strlen(buffer) != 0 && cmd.args[counter[0] + 1] != 0)
		buffer[counter[2]++] = ' ';
	counter[0]++;
}

int	echo(t_cmd cmd)
{
	char	*buffer;
	int		n_option;
	int		size;
	int		counter[3];

	counter[0] = 1;
	counter[1] = 0;
	counter[2] = 0;
	n_option = 0;
	size = echo_read(cmd, &n_option);
	buffer = malloc(sizeof(char) * (size + n_option));
	buffer[0] = '\0';
	while (cmd.args[counter[0]] != 0)
		grab_line_echo(counter, cmd, buffer);
	if (n_option != 1)
		buffer[counter[2]++] = '\n';
	buffer[counter[2]] = '\0';
	ft_putstr_fd(buffer, 1);
	free(buffer);
	exit(0);
	return (0);
}

int	check_option(char *str)
{
	int	i;

	i = 1;
	if (str[0] == '-')
	{
		if (str[1] == '\0')
			return (0);
		while (str[i] != '\0')
		{
			if (str[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	echo_read(t_cmd cmd, int *n_option)
{
	int	i;
	int	output;

	i = 1;
	output = 0;
	while (cmd.args[i] != 0)
	{
		if (check_option(cmd.args[i]) == 1 && output == 0)
			*n_option = 1;
		else
			output += ft_strlen(cmd.args[i]);
		output += 1;
		i++;
	}
	return (output);
}
