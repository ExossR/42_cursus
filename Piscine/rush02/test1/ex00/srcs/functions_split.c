/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:41:51 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/02 23:05:54 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*init_tab_zero(char *str)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

char	*add_val_tabrest(char *result, char *str, int key)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		result[i] = str[key + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_mod(int mod)
{
	if (mod == 0)
		return (3);
	else if (mod == 1)
		return (1);
	else
		return (2);
}

int	ft_atoi_check_unsignedint(char *str)
{
	unsigned int	i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		if (nb * 10 + (str[i] - 48) > 4294967295)
			return (0);
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (1);
}
