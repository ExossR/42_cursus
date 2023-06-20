/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:23:25 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/16 18:12:21 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	is_spacex(char a)
{
	if (a == ' ' || a == '\t' || a == '\r' || a == '\v'
		|| a == '\f' || a == '\n')
		return (true);
	return (false);
}

char	**split_with_quote(char *s, bool *output_bool)
{
	t_squote	*output;
	char		**tmp;

	output = init_split_quote();
	output->tab = ft_calloc((sizeof(char *)), (number_of_word(s) + 1));
	while (s[output->i] != 0)
	{
		if (is_spacex(s[output->i]) && output->is_in == false
			&& !is_spacex(s[output->i - 1]))
			add_to_tab(output);
		else if (s[output->i] == '\'' || s[output->i] == '\"')
			handle_quote(output, s, output_bool);
		else if (s[output->i] == '>' || s[output->i] == '<')
			handle_redirect(output, s);
		else if (!is_spacex(s[output->i]) || output->is_in == true)
			output->buff = ft_strcat_only_one(output->buff, s[output->i]);
		output->i++;
	}
	add_to_tab(output);
	output->tab[output->j] = 0;
	free(output->buff);
	tmp = output->tab;
	free(output);
	return (tmp);
}

char	**ft_split_pipe_quote(char *s)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	str = calloc((nb_word_pipe(s) + 1), sizeof(char *));
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_charset(s[i]))
			i++;
		k = i;
		while (s[i] && !is_charset(s[i]))
		{
			if (s[i] && (s[i] == '\'' || s[i] == '"'))
				i += next_word(s + i, s[i]) - 1;
			i++;
		}
		if (k != i)
			str[j++] = ft_strndup(s + k, i - k);
	}
	str[j] = 0;
	return (str);
}
