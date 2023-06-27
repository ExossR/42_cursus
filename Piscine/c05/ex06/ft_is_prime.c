/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:53:46 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/24 10:57:30 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 5;
	if (nb == 2)
		return (1);
	else if (nb == 1 || nb == 0)
		return (0);
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

/*#include <stdio.h>

int	main(void)
{
	int i = 2147483647;
	printf("%d : %d", i, ft_is_prime(i));
}*/
