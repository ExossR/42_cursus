/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_syntaxe_tokens.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:00:14 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/16 17:56:18 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	token_pipe(t_type_token *lst, char *line)
{
	if (begin_is_empty(line, lst->token) == true)
		return (true);
	if (end_is_empty(line, lst->pos) == true)
		return (true);
	if (lst->nb_in_str_valid > 1 && inter_is_empty(line, lst->pos, '|') == true)
		return (true);
	return (false);
}

bool	token_chevron_right(t_type_token *lst, char *line)
{
	int	i;

	i = lst->pos + 1;
	if (end_is_empty(line, lst->pos) == true)
		return (true);
	if (lst->nb_in_str_valid > 1 && inter_is_empty(line, lst->pos, '>') == true)
		return (true);
	if (nb_of_char_valid(line, '<') > 0 && inter_is_empty(line, lst->pos, '<'))
		return (true);
	while (line[i] && is_space(line[i]))
		i++;
	if (line[i] == '|')
		return (true);
	return (false);
}

bool	token_chevron_left(t_type_token *lst, char *line)
{
	int	i;

	i = lst->pos + 1;
	if (end_is_empty(line, lst->pos) == true)
		return (true);
	if (lst->nb_in_str_valid > 1 && inter_is_empty(line, lst->pos, '<') == true)
		return (true);
	if (nb_of_char_valid(line, '>') > 0 && inter_is_empty(line, lst->pos, '>'))
		return (true);
	while (line[i] && is_space(line[i]))
		i++;
	if (line[i] == '|')
		return (true);
	return (false);
}

bool	token_quote(t_type_token *lst)
{
	if (lst->nb_in_str_valid % 2 != 0)
		return (true);
	return (false);
}
