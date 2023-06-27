/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:36:06 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/24 11:01:26 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 0;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		while (power > 0)
		{
			if (res != 0)
				res = res * nb;
			else
				res = nb;
			power--;
		}
	}
	return (res);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d", ft_iterative_power(5, 1));
}*/
