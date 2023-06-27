/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:00:10 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/22 13:32:06 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb >= 0)
	{
		res = 1;
		while (nb > 1)
		{
			res = res * nb;
			nb--;
		}
		return (res);
	}
	else
		return (0);
}

/*int	main(int argc, char **argv)
{
	printf("%d", ft_iterative_factorial(0));
}*/
