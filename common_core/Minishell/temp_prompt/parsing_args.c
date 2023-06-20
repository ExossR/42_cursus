/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:07:17 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/16 19:21:42 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/**
 * Va transformer la ligne sur les principes du $ :
 * - S'il est entre ' alors on l'écrit direct
 * - Sinon on part chercher la valeur de la variable
*/

char	*transform_line(char **env, char *line)
{
	int		i;
	bool	is_in_single;
	bool	is_in_double;

	i = 0;
	is_in_single = false;
	is_in_double = false;
	while (line[i] != 0)
	{
		if (line[i] == '\"' && is_in_single == false)
			is_in_double = !is_in_double;
		if (line[i] == '\'' && is_in_double == false)
			is_in_single = !is_in_single;
		if (line[i] == '$' && is_in_single == false)
		{
			if (line[++i] == '?')
				return (transforming_line(line,
						ft_itoa(g_struct->value_of_return)));
			else if (line[i] == '\0' || line[i] == ' ')
				return (transforming_line(line, ft_strdup("$")));
			return (transforming_line(line, search_var_env(env, line + i)));
		}
		i++;
	}
	return (line);
}

char	*first_of_list(char **sp)
{
	int	i;

	i = 0;
	while (sp[i] != 0)
	{
		if (is_token(sp[i]) == true)
			i++;
		else
			return (sp[i]);
		i++;
	}
	return (0);
}

char	*fill_name_cmd(t_cmd cmd, int *pos, char **sp)
{
	int		i;
	char	*name;

	(void) cmd;
	i = 0;
	name = 0;
	while (sp[i] != 0)
	{
		*pos = i;
		name = find_path_cmd(g_struct->g_env, sp[i]);
		if (sp[i][0] == '>' || sp[i][0] == '<')
			i += 2;
		else if (is_builtins(sp[i]) == 1)
		{
			free(name);
			name = ft_strdup(sp[i]);
			return (name);
		}
		else if (name)
			return (name);
		else
			return (ft_strdup(sp[i]));
	}
	return (ft_strdup(""));
}

char	**fill_args_cmd(int pos, char **sp, bool *args_bool)
{
	char	**output;
	int		j;

	j = 0;
	output = 0;
	output = ft_calloc((length_of_tab(sp) + 1), sizeof(char *));
	while (sp[pos] != 0)
	{
		output[j] = 0;
		if (is_token(sp[pos]) == true && args_bool[pos] == false
			&& sp[pos][0] != '\0')
			pos += 2;
		else
		{
			output[j] = ft_strdup(sp[pos]);
			j++;
			pos++;
		}
	}
	output[j] = 0;
	return (output);
}
