/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:22:53 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 17:57:11 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	copy_env(char **env_old, char **new_env)
{
	int	i;

	i = 0;
	while (env_old[i] != 0)
	{
		new_env[i] = ft_strdup(env_old[i]);
		i++;
	}
	return (0);
}

int	size_of_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != 0)
		i++;
	return (i);
}

int	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != 0)
		free(env[i++]);
	free(env);
	return (0);
}

int	find_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}
