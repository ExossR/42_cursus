/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:34:11 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/07 15:08:27 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_temp;

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
