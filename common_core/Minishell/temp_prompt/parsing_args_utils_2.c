/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:45:48 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/16 10:48:04 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	size_var_env(char *env)
{
	int	i;

	i = 0;
	while (env[i] != '=')
		i++;
	return (i);
}

int	len_of_old_env(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (str[i] == '$')
		{
			i++;
			if (str[i] == '?')
				return (1);
			while ((ft_isalnum(str[i]) || str[i] == '_' ) && str[i] != '\0')
			{
				i++;
				j++;
			}
			return (j);
		}
		i++;
	}
	return (i);
}

char	*transforming_line(char *line, char *val_var)
{
	int		i;
	char	*res;
	char	*tmp;

	i = 0;
	res = 0;
	while (line[i] != '$')
		i++;
	res = ft_strndup(line, i);
	tmp = ft_strjoin(res, val_var);
	free(res);
	res = ft_strjoin(tmp, &line[i + len_of_old_env(line)] + 1);
	free(tmp);
	free(val_var);
	return (res);
}
