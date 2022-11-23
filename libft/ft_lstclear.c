/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:18:11 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/11 10:35:18 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst)
	{
		if (*lst && del)
		{
			while (*lst)
			{
				temp = (*lst)->next;
				ft_lstdelone(*lst, del);
				*lst = temp;
			}
		}
		lst = 0;
	}
	free(lst);
}
