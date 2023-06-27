/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:::    :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:42:51 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/15 19:56:40 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		count_size(char *str)
{
	
}

void	ft_putnbr(int nb)
{
	int		b;
	int		i;
	char	*tab;

	b = 0;
	if (nb < 9 && nb >= 0)
		write(1, &nb, 1);
	else
	{
		if (nb < 0)
			b = 1;
		
	}
}

int		main(void)
{
	ft_putnbr(5);
}
