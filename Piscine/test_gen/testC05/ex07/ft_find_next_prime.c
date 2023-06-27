/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:29:33 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/24 11:05:05 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 5;
	if (nb == 2)
		return (1);
	else if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	else
	{
		while (i < nb / 4)
		{
			if (nb % i == 0)
				return (0);
			i += 2;
		}
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	odd;

	odd = 0;
	if (nb % 2 != 0)
		odd = 1;
	if (nb == 2)
		return (3);
	while (!ft_is_prime(nb))
	{
		if (odd == 1)
			nb += 2;
		else
		{
			nb++;
			odd = 1;
		}
	}
	return (nb);
}

/*#include <stdio.h>

int	main(void)
{
	int i = 711;
	printf("%d : %d", i, ft_find_next_prime(i));
}*/
