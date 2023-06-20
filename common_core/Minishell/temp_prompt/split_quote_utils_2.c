/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:24:48 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/16 15:02:57 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	next_word(char *str, char del)
{
	int		i;
	bool	founded;

	founded = false;
	i = 1;
	if (del != '\'' && del != '\"')
		founded = true;
	while (str[i] != '\0')
	{
		if (founded == true)
			return (i);
		else if (str[i] == del && (del == '\'' || del == '\"'))
			founded = true;
		i++;
	}
	return (i);
}

t_squote	*init_split_quote(void)
{
	t_squote	*output;

	output = ft_calloc(sizeof(t_squote), 1);
	output->tab = 0;
	output->i = 0;
	output->j = 0;
	output->buff = ft_calloc(sizeof(char), 1);
	output->is_in = false;
	output->which_is_in = 0;
	return (output);
}

int	is_charset(char s)
{
	if (s == '|')
		return (1);
	return (0);
}

int	nb_word_pipe(char *s)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] && is_charset(s[i]))
			i++;
		if (s[i] && !is_charset(s[i]))
			nb++;
		while (s[i] && !is_charset(s[i]))
		{
			if (s[i] && (s[i] == '\'' || s[i] == '"'))
				i += next_word(s + i, s[i]) - 1;
			i++;
		}
	}
	return (nb);
}
