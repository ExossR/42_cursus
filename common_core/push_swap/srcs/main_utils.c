/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:25:31 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/13 19:57:38 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr[i])
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
	}
	free(arr);
}

long long	ft_atoi(const char *nptr)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (sign * res);
}

t_swap	*new_elem(int number)
{
	t_swap	*new;

	new = malloc(sizeof(t_swap));
	if (new == 0)
		return (0);
	new->content = number;
	new->next = 0;
	return (new);
}

void	ft_lstadd_back(t_swap *lst, t_swap *new)
{
	t_swap	*lst_temp;

	lst_temp = lst;
	while (lst_temp->next != 0)
		lst_temp = lst_temp->next;
	lst_temp->next = new;
}
