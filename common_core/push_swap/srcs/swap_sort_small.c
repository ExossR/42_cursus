/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sort_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:07:30 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/19 17:52:42 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*sort_three(t_swap *list)
{
	if (list->next->next->content < list->next->content
		&& list->next->next->content < list->content)
	{
		if (list->content > list->next->content)
		{
			swap(&list, 1);
			reverse_rotate(&list, 1);
		}
		else
			reverse_rotate(&list, 1);
	}
	else if (list->next->next->content > list->content)
	{
		swap(&list, 1);
		if (is_sorted(list) != 1)
			rotate(&list, 1);
	}
	else
		rotate(&list, 1);
	return (list);
}

int	pos_mini(t_swap *list)
{
	int	pos;
	int	min;
	int	i;

	i = 0;
	pos = 0;
	min = list->content;
	while (list->next != 0)
	{
		if (min > list->content)
		{
			min = list->content;
			pos = i;
		}
		list = list->next;
		i++;
	}
	if (min > list->content)
	{
		min = list->content;
		pos = i;
	}
	return (pos);
}

t_swap	*sort_four(t_swap *list)
{
	t_swap	*l2;
	int		i;
	int		pos_min;

	l2 = 0;
	i = 0;
	pos_min = pos_mini(list);
	while (i != pos_min)
	{
		rotate(&list, 1);
		i++;
	}
	push_b(&list, &l2);
	list = sort_three(list);
	push_a(&list, &l2);
	return (list);
}

t_swap	*sort_five(t_swap *list)
{
	t_swap	*l2;
	int		i;
	int		pos_min;

	l2 = 0;
	i = 0;
	pos_min = pos_mini(list);
	while (i != pos_min)
	{
		rotate(&list, 1);
		i++;
	}
	push_b(&list, &l2);
	i = 0;
	pos_min = pos_mini(list);
	while (i != pos_min)
	{
		rotate(&list, 1);
		i++;
	}
	push_b(&list, &l2);
	list = sort_three(list);
	push_a(&list, &l2);
	push_a(&list, &l2);
	return (list);
}
