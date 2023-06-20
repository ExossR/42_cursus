/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:59:37 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/09 11:14:36 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	free_cmd_line(t_cmd_line *cmd_line)
{
	int	i;

	i = 0;
	if (cmd_line != 0)
	{
		while (i < cmd_line->size_of_tab)
		{
			free_arr(cmd_line->commands[i].args);
			free_arr(cmd_line->commands[i].redirect_out);
			free_arr(cmd_line->commands[i].redirect_in);
			free_arr(cmd_line->commands[i].here_doc);
			free_arr(cmd_line->commands[i].redirect_append);
			if (cmd_line->commands[i].name != 0)
				free(cmd_line->commands[i].name);
			i++;
		}
		free(cmd_line->commands);
		free(cmd_line);
	}
}
