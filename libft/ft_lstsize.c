/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:35:09 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/07 15:11:31 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (lst)
	{
		while (lst->next != 0)
		{
			lst = lst->next;
			i++;
		}
	}
	else
		return (0);
	return (i);
}
