/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:05:45 by asahonet          #+#    #+#             */
/*   Updated: 2023/01/04 19:24:05 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	verif_arg(int argc, char **argv)
{
	if (argc != 5)
	{
		write(2, "Usage : ./pipex infile cmd1 cmd2 outfile\n", 41);
		return (1);
	}
	if (access(argv[1], F_OK | R_OK) != 0)
		perror("access");
	return (0);
}

char	*verif_path_cmd(char **paths, char **cmd_part)
{
	int		i;
	char	*cmd_path;

	i = 0;
	if (access(cmd_part[0], F_OK) == 0)
		return (cmd_part[0]);
	cmd_path = ft_strjoin(paths[i], "/");
	cmd_path = ft_strjoin(cmd_path, cmd_part[0]);
	while (paths[i] && access(cmd_path, F_OK) != 0)
	{
		i++;
		free(cmd_path);
		cmd_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd_part[0]);
	}
	if (access(cmd_path, F_OK) != 0)
	{
		free(cmd_path);
		return (0);
	}
	return (cmd_path);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*find_path_cmd(char **env, char *cmd)
{
	int		i;
	char	**paths;
	char	**cmd_part;
	char	*str;

	i = -1;
	while (env[++i])
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
			&& env[i][3] == 'H' && env[i][4] == '=')
			break ;
	env += i;
	(*env) += 5;
	paths = ft_split(*env, ':');
	cmd_part = ft_split(cmd, ' ');
	str = verif_path_cmd(paths, cmd_part);
	if (str == 0)
	{
		free_arr(paths);
		free_arr(cmd_part);
		return (0);
	}
	free_arr(paths);
	free_arr(cmd_part);
	return (str);
}
