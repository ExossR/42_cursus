/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:24:33 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 14:18:05 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*truncate_env_var(char *str)
{
	char	*output;
	int		i;

	i = 0;
	output = ft_strdup(str);
	while (output[i] != 0)
	{
		if (output[i] == '=')
			output[i] = '\0';
		i++;
	}
	return (output);
}

char	*search_var_env(char **env, char *line)
{
	int		i;
	char	*var;
	int		j;
	char	*truncate_env;

	i = 0;
	while (ft_isalnum(line[i]) || line[i] == '_')
		i++;
	var = ft_strndup(line, i);
	j = i;
	i = 0;
	while (env[i])
	{
		truncate_env = truncate_env_var(env[i]);
		if (double_check(truncate_env, var))
		{
			free(var);
			free(truncate_env);
			return (ft_strdup(&env[i][j + 1]));
		}
		free(truncate_env);
		i++;
	}
	free(var);
	return (ft_strdup(""));
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr != 0)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

char	*verif_path_cmd(char **paths, char *cmd_part)
{
	int		i;
	char	*cmd_path;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin(paths[i], "/");
	cmd_path = ft_strjoin(tmp, cmd_part);
	free(tmp);
	while (paths[i + 1] != 0 && access(cmd_path, F_OK) != 0)
	{
		i++;
		free(cmd_path);
		tmp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(tmp, cmd_part);
		free(tmp);
	}
	if (access(cmd_path, F_OK) != 0)
	{
		free(cmd_path);
		if (access(cmd_part, F_OK) == 0)
			return (ft_strdup(cmd_part));
		return (0);
	}
	return (cmd_path);
}

int	size_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}
