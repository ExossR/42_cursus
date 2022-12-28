/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:54:28 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/13 19:54:46 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_swap *lst)
{
	t_swap	*temp;

	if (lst)
	{
		while (lst)
		{
			temp = lst->next;
			lst->content = 0;
			lst->next = 0;
			free(lst);
			lst = temp;
		}
	}
	free(lst);
}
