/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:17:47 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/28 14:54:24 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_swap *list)
{
	while (list->next != 0)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

int	is_empty(t_swap *list)
{
	if (list)
	{
		if (!(list->content || list->next))
			return (0);
	}
	return (1);
}

t_swap	*sort_small_stack(t_swap *list, int size)
{
	if (is_sorted(list) == 1)
		return (list);
	if (size == 2)
	{
		if (list->content > list->next->content)
			swap(&list, 1);
		return (list);
	}
	else if (size == 3)
		return (sort_three(list));
	else if (size == 4)
		return (sort_four(list));
	else
		return (sort_five(list));
}

t_swap	*sort_stack(t_swap *list, int size)
{
	t_swap	*l2;
	int		i;
	int		j;

	i = 0;
	l2 = 0;
	if (have_neg_in(list) == 1)
		nullify_neg(list);
	while (is_sorted(list) != 1)
	{
		j = -1;
		while (++j < size)
		{
			if (((list->content >> i) & 1) == 1)
				rotate(&list, 1);
			else
				push_b(&list, &l2);
		}
		while (l2 != 0)
			push_a(&list, &l2);
		i++;
	}
	return (list);
}
