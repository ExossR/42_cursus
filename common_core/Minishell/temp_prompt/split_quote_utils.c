/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:24:48 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/17 10:29:27 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	number_of_word(char *str)
{
	int	i;
	int	output;

	i = 0;
	output = 1;
	while (str[i] != '\0')
	{
		if (i != 0)
		{
			if (is_space(str[i]) && !is_space(str[i - 1]))
				output++;
			if (str[i] == '>' || str[i] == '<')
			{
				output += 2;
				if (str[i + 1] == '<' || str[i + 1] == '>')
					i++;
			}
		}
		i++;
	}
	return (output);
}

char	*ft_strcat_only_one(char *str, char c)
{
	char	*tmp;
	char	tmp_str[2];

	tmp_str[0] = c;
	tmp_str[1] = '\0';
	tmp = ft_strjoin(str, tmp_str);
	free(str);
	return (tmp);
}

void	add_to_tab(t_squote *output)
{
	if (output->buff[0] != 0)
		output->tab[output->j++] = ft_strdup(output->buff);
	output->buff[0] = 0;
}

void	special_add_to_tab(t_squote *output)
{
	if (output->buff[0] == 0)
		output->tab[output->j++] = ft_strdup("");
}

void	handle_quote(t_squote *output, char *s, bool *output_bool)
{
	output_bool[output->j] = true;
	if (s[output->i] == s[output->i + 1]
		&& (is_space(s[output->i + 2]) || s[output->i + 2] == '\0'))
	{
		special_add_to_tab(output);
		output->i++;
	}
	else
	{
		if (output->which_is_in == 0)
			output->which_is_in = s[output->i];
		else if (output->which_is_in == s[output->i])
			output->which_is_in = 0;
		else
			output->buff = ft_strcat_only_one(output->buff, s[output->i]);
		if (output->which_is_in == s[output->i] || output->which_is_in == 0)
			output->is_in = !output->is_in;
	}
}
