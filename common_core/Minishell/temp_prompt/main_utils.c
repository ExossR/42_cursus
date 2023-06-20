/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:32:15 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/17 11:12:02 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	**recreate_env(void)
{
	char	**res;
	char	buff[PATH_MAX];

	res = 0;
	getcwd(buff, PATH_MAX);
	g_struct->is_in_env = malloc(sizeof(bool) * 3);
	res = malloc(4 * sizeof(char *));
	g_struct->is_in_env[0] = true;
	g_struct->is_in_env[1] = true;
	g_struct->is_in_env[2] = true;
	res[0] = ft_strjoin("PWD=", buff);
	res[1] = ft_strdup("SHLVL=0");
	res[2] = ft_strdup("_=/usr/bin/env");
	res[3] = 0;
	return (res);
}

char	**get_tot_env(char **env)
{
	int		i;
	char	**cp_env;

	i = 0;
	if (!env || !env[0])
		return (recreate_env());
	while (env[i])
		i++;
	cp_env = malloc((i + 1) * sizeof(char *));
	g_struct->is_in_env = malloc(i * sizeof(bool));
	i = 0;
	while (env[i])
	{
		cp_env[i] = ft_strdup(env[i]);
		g_struct->is_in_env[i] = true;
		i++;
	}
	cp_env[i] = 0;
	return (cp_env);
}
