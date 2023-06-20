/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:22:53 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 19:19:14 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	special_print(t_cmd cmd)
{
	char	**tmp_env;
	int		size;
	char	*buffer;

	size = size_of_env(g_struct->g_env);
	tmp_env = malloc(sizeof(char *) * (size + 1));
	copy_env(g_struct->g_env, tmp_env);
	tmp_env[size] = 0;
	ft_sort_string_tab(tmp_env);
	buffer = tf_split(tmp_env);
	ft_putstr_fd(buffer, 1);
	free(buffer);
	free_arr(tmp_env);
	return (exit_or_return(cmd, 0));
}

int	ft_export(t_cmd cmd)
{
	int	i;
	int	size;
	int	rtn;

	size = size_of_env(g_struct->g_env);
	if (cmd.args[1] == 0)
		return (special_print(cmd));
	i = 1;
	while (cmd.args[i] != 0)
	{
		rtn = check_env_var(cmd.args[i], g_struct->g_env);
		if (rtn == 1)
		{
			g_struct->value_of_return = 1;
			return (exit_or_return(cmd, 1));
		}
		else if (rtn == 0)
			add_to_env_tab(true, cmd, i);
		else if (rtn == 3 && is_in_tab_e(cmd.args[i]) == false)
			add_to_env_tab(false, cmd, i);
		i++;
	}
	return (exit_or_return(cmd, 0));
}

int	grab_line_check_env_var(char *str, int i)
{
	free(g_struct->g_env[i]);
	g_struct->g_env[i] = ft_strdup(str);
	g_struct->is_in_env[i] = true;
	return (2);
}

int	a_green_mouse(char *str)
{
	printf("bash: export: `%s': not a valid identifier\n", str);
	return (1);
}

int	check_env_var(char *str, char **env)
{
	int		i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i++] != '_')
		return (a_green_mouse(str));
	while (str[i] != '=' && str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == false && str[i] != '_')
			return (a_green_mouse(str));
		i++;
	}
	if (str[i] == '\0')
		return (3);
	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(str, env[i], find_equal(str)) == 0)
			return (grab_line_check_env_var(str, i));
		i++;
	}
	return (0);
}
