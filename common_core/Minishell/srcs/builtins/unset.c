/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:22:53 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 19:20:34 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	unset(t_cmd cmd)
{
	int		i;
	char	**tmp_env;
	int		size;
	int		j;

	i = 1;
	j = 0;
	while (cmd.args[i] != 0)
	{
		if (check_env_var_unset(cmd.args[i], g_struct->g_env) == 0)
		{
			size = size_of_env(g_struct->g_env);
			tmp_env = malloc(sizeof(char *) * (size));
			copy_and_remove(g_struct->g_env, tmp_env, cmd.args[i]);
			tmp_env[size - 1] = 0;
			free_env(g_struct->g_env);
			g_struct->g_env = tmp_env;
		}
		i++;
	}
	return (exit_or_return(cmd, 0));
}

int	check_env_var_unset(char *str, char **env)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == false && str[i] != '_')
		{
			printf("bash: unset: `%s': not a valid identifier\n", str);
			return (1);
		}
		i++;
	}
	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(str, env[i], ft_strlen(str)) == 0)
		{
			if (env[i][ft_strlen(str)] == '=')
				return (0);
		}
		i++;
	}
	return (1);
}

int	copy_and_remove(char **env_old, char **new_env, char *target)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env_old[i] != 0)
	{
		if (ft_strncmp(target, env_old[i], ft_strlen(target))
			== 0 && env_old[i][ft_strlen(target)] == '=')
			i++;
		else
		{
			new_env[j] = ft_strdup(env_old[i]);
			j++;
			i++;
		}
	}
	return (0);
}
