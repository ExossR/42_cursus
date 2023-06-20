/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:22:43 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 18:12:26 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	length_of_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

int	find_in_tab(char **tab, char *target, bool *is_quote)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		if (ft_strncmp(tab[i], target, ft_strlen(target))
			== 0 && is_quote[i] == false)
		{
			if (ft_strncmp(tab[i], target, ft_strlen(tab[i]))
				== 0 && is_quote[i] == false)
				return (i);
		}
		i++;
	}
	return (-1);
}

bool	is_token(char *str)
{
	if (double_check(str, ">") == true
		|| double_check(str, ">>") == true
		|| double_check(str, "<") == true
		|| double_check(str, "<<") == true)
		return (true);
	return (false);
}

char	**this_redirect(char **tab, char *target, bool *args_bool)
{
	int		index;
	int		j;
	char	**output;
	int		tmp;

	j = 0;
	index = find_in_tab(tab, target, args_bool);
	if (index == -1)
		return (0);
	output = ft_calloc((length_of_tab(tab) + 1), sizeof(char *));
	while (index != -1)
	{
		index++;
		output[j++] = ft_strdup(tab[index]);
		tmp = find_in_tab(&tab[index], target, args_bool);
		if (tmp == -1)
			break ;
		index += tmp;
	}
	output[j] = 0;
	return (output);
}
