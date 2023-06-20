/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_utils_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:24:33 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 11:03:50 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*find_path_cmd(char **env, char *cmd)
{
	int		i;
	char	**paths;
	char	*str;

	i = -1;
	if (cmd[0] == 0)
		return (ft_strdup(""));
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
	}
	if (i == size_env(env))
		return (ft_strdup(cmd));
	paths = ft_split(env[i] + 5, ':');
	if (paths == 0 || paths[0] == 0)
		return (ft_strdup(cmd));
	str = verif_path_cmd(paths, cmd);
	if (str == 0)
	{
		free_arr(paths);
		return (0);
	}
	free_arr(paths);
	return (str);
}

int	is_builtins(char *name)
{
	char	*builtins[8];
	int		i;

	i = 0;
	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	builtins[7] = 0;
	while (builtins[i])
	{
		if (double_check(builtins[i], name) == true)
			return (1);
		i++;
	}
	return (0);
}
