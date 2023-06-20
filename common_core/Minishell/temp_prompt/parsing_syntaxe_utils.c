/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_syntaxe_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:47:54 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/04 12:02:45 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\f' || c == '\r')
		return (true);
	return (false);
}

bool	begin_is_empty(char *line, char token)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (line[i] == token)
		return (true);
	return (false);
}

bool	end_is_empty(char *line, int pos)
{
	int	i;

	i = pos + 1;
	while (line[i] && is_space(line[i]))
		i++;
	if (line[i] == '\0')
		return (true);
	return (false);
}

bool	inter_is_empty(char *line, int pos, char token)
{
	int	i;

	i = pos + 1;
	while (is_space(line[i]))
		i++;
	if (token == '>' || token == '<')
	{
		if (line[i + 1] != 0 && line[i] == '<'
			&& line[i - 1] == '<' && line [i + 1] == '<')
			return (true);
		else if (line[i] == '<' && line[i - 1] == '<')
			return (false);
		if (line[i + 1] != 0 && line[i] == '>'
			&& line[i - 1] == '>' && line [i + 1] == '>')
			return (true);
		else if (line[i] == '>' && line[i - 1] == '>')
			return (false);
	}
	if (line[i] == token || line[i] == '|')
		return (true);
	return (false);
}

int	nb_of_char_valid(char *line, char token)
{
	int	i;
	int	nb;
	int	size;

	i = 0;
	nb = 0;
	size = 0;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			nb += add_count_number_quote(token, line[i]);
			size = next_word(line + i, line[i]);
			i += size - 1;
			if (size > 1 && line[i] == '"' && token == '"')
				nb++;
			else if (size > 1 && line[i] == '\'' && token == '\'')
				nb++;
		}
		else if (line[i] == token)
			nb++;
		i++;
	}
	return (nb);
}
