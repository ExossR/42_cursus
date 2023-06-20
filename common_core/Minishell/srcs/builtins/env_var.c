/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:37:48 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 18:11:16 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*found_var_name(char *str)
{
	int		i;
	int		j;
	char	*test;
	char	*output;

	test = ft_strdup(str);
	i = 0;
	j = 0;
	while (test[i] != '\0')
	{
		if (test[i] == '$')
		{
			i++;
			j = i;
			while (test[i] != ' ' && test[i] != '\0')
				i++;
			test[i] = '\0';
		}
		i++;
	}
	output = ft_strdup(&test[j]);
	free(test);
	return (output);
}

char	*before_dollar(char *line)
{
	int		i;
	char	*str;

	str = ft_strdup(line);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '$')
			str[i] = '\0';
		i++;
	}
	return (str);
}

char	*after_dollar(char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '$')
		{
			while (line[i] != ' ' && line[i] != '\0')
				i++;
			return (&line[i]);
		}
		i++;
	}
	return (line);
}

char	*replace_env_var(char *line, char **env)
{
	int		i;
	char	*name;
	char	*tmp;
	char	*tmp_2;

	i = 0;
	tmp = found_var_name(line);
	while (env[i] != 0)
	{
		if (ft_strncmp(env[i], tmp, ft_strlen(tmp)) == 0)
		{
			name = &env[i][ft_strlen(tmp) + 1];
			free(tmp);
			break ;
		}
		i++;
	}
	tmp_2 = before_dollar(line);
	tmp = ft_strjoin(tmp_2, name);
	free(tmp_2);
	name = ft_strjoin(tmp, after_dollar(line));
	free(tmp);
	return (name);
}
