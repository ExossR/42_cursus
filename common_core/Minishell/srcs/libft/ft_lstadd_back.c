/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:12:06 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/10 18:03:01 by jbranche         ###   ########.fr       */
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
