/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:22:53 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 19:19:34 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_strcmp(char *s1, char *s2);

int	copy_bool_env(bool *env_old, bool *new_env, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		new_env[i] = env_old[i];
		i++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		swapped;
	char	*temp;

	swapped = 1;
	while (swapped != 0)
	{
		swapped = 0;
		i = 1;
		while (tab[i] != 0)
		{
			if (ft_strcmp(tab[i], tab[i - 1]) < 0)
			{
				temp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	add_to_env_tab(bool in_env, t_cmd cmd, int i)
{
	char	**tmp_env;
	bool	*tmp_bool_env;
	int		size;

	size = size_of_env(g_struct->g_env);
	tmp_env = malloc(sizeof(char *) * (size + 2));
	tmp_bool_env = calloc(sizeof(bool), (size + 1));
	copy_env((g_struct->g_env), tmp_env);
	copy_bool_env((g_struct->is_in_env), tmp_bool_env, size + 1);
	tmp_env[size] = ft_strdup(cmd.args[i]);
	tmp_env[size + 1] = 0;
	if (in_env == true)
		tmp_bool_env[size] = true;
	free_arr(g_struct->g_env);
	free(g_struct->is_in_env);
	g_struct->g_env = tmp_env;
	g_struct->is_in_env = tmp_bool_env;
}

bool	is_in_tab_e(char *str)
{
	int	i;

	i = 0;
	while (g_struct->g_env[i] != 0)
	{
		if (ft_strncmp(str, g_struct->g_env[i], ft_strlen(str) + 1) == 0)
			return (true);
		i++;
	}
	return (false);
}
