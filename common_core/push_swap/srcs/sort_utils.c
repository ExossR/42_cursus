/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:39:11 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/16 19:46:08 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_swap **lst, int i)
{
	t_swap	*tmp;
	t_swap	*tmp_f;

	if (lst)
	{
		if (*lst)
		{
			tmp = (*lst);
			tmp_f = (*lst)->next;
			tmp = ft_lstlast(tmp);
			(*lst)->next = 0;
			tmp->next = (*lst);
			(*lst) = tmp_f;
			if (i == 1)
				write(1, "ra\n", 3);
			else
				write(1, "rb\n", 3);
		}
	}
}

void	rrotate(t_swap **lst_a, t_swap **lst_b)
{
	rotate(lst_a, 1);
	rotate(lst_b, 2);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_swap **lst, int i)
{
	t_swap	*tmp_f;
	t_swap	*tmp_l;

	tmp_f = (*lst);
	tmp_l = ft_lstlast(tmp_f);
	while ((*lst)->next->next != 0)
		(*lst) = (*lst)->next;
	(*lst)->next = 0;
	tmp_l->next = tmp_f;
	if (i == 1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	rrrotate(t_swap **lst_a, t_swap **lst_b)
{
	reverse_rotate(lst_a, 1);
	reverse_rotate(lst_b, 2);
	write(1, "rrr\n", 4);
}

t_swap	*ft_lstlast(t_swap *lst)
{
	if (lst)
	{
		while (lst->next != 0)
			lst = lst->next;
	}
	else
		return (0);
	return (lst);
}
