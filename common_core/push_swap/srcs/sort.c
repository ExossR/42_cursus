/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:13:16 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/17 12:01:55 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_swap **lst, int i)
{
	int	tmp;

	if (lst)
	{
		if (*lst)
		{
			if ((*lst)->next != 0)
			{
				tmp = (*lst)->content;
				(*lst)->content = (*lst)->next->content;
				(*lst)->next->content = tmp;
				if (i == 1)
					write(1, "sa\n", 3);
				else
					write(1, "sb\n", 3);
			}
		}
	}
}

void	sswap(t_swap **lst_a, t_swap **lst_b)
{
	swap(lst_a, 1);
	swap(lst_b, 2);
	write(1, "ss\n", 3);
}

void	push_a(t_swap **lst_a, t_swap **lst_b)
{
	t_swap	*tmp;

	if (lst_b)
	{
		if (*lst_b)
		{
			tmp = (*lst_b);
			(*lst_b) = (*lst_b)->next;
			tmp->next = (*lst_a);
			(*lst_a) = tmp;
			write(1, "pa\n", 3);
		}
	}
}

void	push_b(t_swap **lst_a, t_swap **lst_b)
{
	t_swap	*tmp;

	if (lst_a)
	{
		if (*lst_a)
		{
			tmp = (*lst_a);
			(*lst_a) = (*lst_a)->next;
			tmp->next = (*lst_b);
			(*lst_b) = tmp;
			write(1, "pb\n", 3);
		}
	}
}
