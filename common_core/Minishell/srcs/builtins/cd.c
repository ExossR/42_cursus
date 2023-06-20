/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:43:19 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 19:17:55 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	exit_or_return(t_cmd cmd, int error)
{
	if (cmd.is_pipe_out == true || cmd.is_pipe_in == true)
	{
		exit (error);
	}
	else
		return (error);
}

void	juggle_cmd(t_cmd cmd, bool age, t_cd_struct a)
{
	char	*tmp;

	(void) cmd;
	if (age == true)
	{
		tmp = g_struct->g_env[a.pos];
		g_struct->g_env[a.pos] = ft_strjoin("PWD=", a.buffer);
		free(tmp);
	}
	else
	{
		tmp = g_struct->g_env[a.old_pwd];
		g_struct->g_env[a.old_pwd] = ft_strjoin("OLDPWD=", a.old_buffer);
		free(tmp);
	}	
}

void	init_cd_struct(t_cd_struct *a, t_cmd cmd)
{
	(void) cmd;
	a->old_pwd = search_in_env(g_struct->g_env, "OLDPWD=");
	a->pos = search_in_env(g_struct->g_env, "PWD=");
	a->home = search_in_env(g_struct->g_env, "HOME=");
}

int	cd(t_cmd cmd)
{
	t_cd_struct	a;

	init_cd_struct(&a, cmd);
	if (getcwd(a.old_buffer, 2048) == NULL)
		exit_or_return(cmd, call_error());
	if (cmd.args[1] == 0)
	{
		if (a.home != -1)
		{
			if (chdir(&g_struct->g_env[a.home][5]) == -1)
				exit_or_return(cmd, call_error());
		}
	}
	else if (chdir(cmd.args[1]) == -1)
		exit_or_return(cmd, call_error());
	if (getcwd(a.buffer, 2048) == NULL)
	{
		call_error();
		exit_or_return(cmd, 1);
	}
	if (a.pos != -1)
		juggle_cmd(cmd, true, a);
	if (a.old_pwd != -1)
		juggle_cmd(cmd, false, a);
	return (exit_or_return(cmd, 0));
}

int	search_in_env(char **env, char *var)
{
	int	i;
	int	size;

	size = ft_strlen(var);
	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(env[i], var, size) == 0)
			return (i);
		i++;
	}
	return (-1);
}
