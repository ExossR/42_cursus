/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:14:48 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/07 16:51:57 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_type_token	*ft_lstnew_token(char *s, char token, int pos)
{
	t_type_token	*new;

	new = malloc(sizeof(t_type_token));
	if (new == 0)
		return (0);
	new->token = token;
	new->nb_in_str_valid = nb_of_char_valid(s, token);
	new->pos = pos;
	new->next = 0;
	return (new);
}

void	ft_lstadd_back_token(t_type_token **lst, t_type_token *new)
{
	t_type_token	*lst_temp;

	if (lst)
	{
		if (*lst)
		{
			lst_temp = *lst;
			while (lst_temp->next != 0)
				lst_temp = lst_temp->next;
			lst_temp->next = new;
		}
		else
			*lst = new;
	}
}

int	ft_lstsize_token(t_type_token *lst)
{
	int	i;

	i = 1;
	if (lst != 0)
	{
		while (lst->next != 0)
		{
			i++;
			lst = lst->next;
		}
	}
	else
		return (0);
	return (i);
}

void	ft_lstclear_token(t_type_token **lst)
{
	t_type_token	*tmp;

	if (*lst == 0 || lst == 0)
		return ;
	while (lst != 0 && *lst != 0)
	{
		tmp = (*lst)->next;
		(*lst)->nb_in_str_valid = 0;
		(*lst)->pos = 0;
		(*lst)->token = 0;
		free(*lst);
		*lst = tmp;
	}
	lst = 0;
}
