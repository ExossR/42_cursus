/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_syntaxe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:51:08 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/16 19:21:53 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_type_token	*prepare_list_token(t_type_token *lst, char *line)
{
	int		i;
	char	*tokens;

	i = 0;
	tokens = "|<>'\"";
	while (line[i])
	{
		if (ft_strchr(tokens, line[i]))
		{
			if (lst == 0)
				lst = ft_lstnew_token(line, line[i], i);
			else
				ft_lstadd_back_token(&lst, ft_lstnew_token(line, line[i], i));
		}
		i++;
	}
	return (lst);
}

bool	catch_error_syntax(t_type_token *lst, char *line)
{
	if (lst->token == '|')
		return (token_pipe(lst, line));
	else if (lst->token == '>')
		return (token_chevron_right(lst, line));
	else if (lst->token == '<')
		return (token_chevron_left(lst, line));
	else if (lst->token == '\'' || lst->token == '"')
		return (token_quote(lst));
	return (false);
}

bool	error_handle(char *line)
{
	t_type_token	*lst_token;
	t_type_token	*tmp;

	lst_token = 0;
	lst_token = prepare_list_token(lst_token, line);
	tmp = lst_token;
	if (ft_lstsize_token(lst_token) == 0)
		return (false);
	while (lst_token != 0)
	{
		if (catch_error_syntax(lst_token, line) == true)
		{
			g_struct->value_of_return = 258;
			ft_lstclear_token(&tmp);
			return (true);
		}
		lst_token = lst_token->next;
	}
	ft_lstclear_token(&tmp);
	return (false);
}
