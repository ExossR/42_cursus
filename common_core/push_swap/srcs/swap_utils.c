/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:49:06 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/21 11:48:00 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_number_stack(t_swap *list)
{
	int	max;

	max = list->content;
	while (list->next != 0)
	{
		if (max < list->content)
			max = list->content;
		list = list->next;
	}
	if (max < list->content)
			max = list->content;
	return (max);
}

int	stack_is_sort(t_swap *list)
{
	t_swap	*tmp;

	while (list->next != 0)
	{
		tmp = list->next;
		if (list->content > tmp->content)
			return (0);
		list = list->next;
	}
	return (1);
}

int	size_list(t_swap *list)
{
	int	i;

	i = 0;
	while (list->next != 0)
	{
		list = list->next;
		i++;
	}
	return (i + 1);
}

int	have_neg_in(t_swap *list)
{
	int	number;

	number = list->content;
	if (number < 0)
		return (1);
	while (list->next != 0)
	{
		number = list->content;
		if (number < 0)
			return (1);
		list = list->next;
	}
	return (0);
}

void	nullify_neg(t_swap *list)
{
	t_swap	*tmp;
	int		min_val;

	tmp = list;
	min_val = tmp->content;
	while (tmp->next != 0)
	{
		if (min_val > tmp->content)
			min_val = tmp->content;
		tmp = tmp->next;
	}
	if (min_val > tmp->content)
		min_val = tmp->content;
	min_val *= -1;
	while (list->next != 0)
	{
		list->content += min_val;
		list = list->next;
	}
	list->content += min_val;
}
