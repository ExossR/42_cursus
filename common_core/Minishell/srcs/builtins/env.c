/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:28:47 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 19:18:09 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	env(t_cmd cmd)
{
	(void) cmd;
	tf_split_env(g_struct->g_env);
	exit(0);
	return (0);
}

void	tf_split_env(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
	{
		if (g_struct->is_in_env[i] == true)
		{
			ft_putstr_fd(tab[i], 1);
			ft_putstr_fd("\n", 1);
		}
		i++;
	}
}
