/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:40:49 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/06 10:56:02 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*cp;

	i = 0;
	cp = malloc(length * sizeof(int));
	while (i < length)
	{
		cp[i] = f(tab[i]);
		i++;
	}
	return (cp);
}
