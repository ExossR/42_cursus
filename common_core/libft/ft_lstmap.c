/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:16:29 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/11 11:30:48 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*temp;

	if (!lst || !del || !f)
		return (0);
	n_lst = 0;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			while (n_lst)
			{
				temp = n_lst->next;
				ft_lstdelone(n_lst, del);
				n_lst = temp;
			}
			return (0);
		}
		ft_lstadd_back(&n_lst, temp);
		lst = lst->next;
	}
	return (n_lst);
}
