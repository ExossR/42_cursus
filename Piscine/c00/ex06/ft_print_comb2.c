/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:18:43 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/15 11:13:52 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_two_char_numbers(int a, int b)
{
	int	da;
	int	ua;
	int	db;
	int	ub;

	da = (a / 10) + 48;
	ua = (a % 10) + 48;
	db = (b / 10) + 48;
	ub = (b % 10) + 48;
	write(1, &da, 1);
	write(1, &ua, 1);
	write(1, " ", 1);
	write(1, &db, 1);
	write(1, &ub, 1);
	if (a != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	x;
	int	n;

	x = 0;
	while (x < 99)
	{
		n = 0;
		while (n < 100)
		{
			if (x < n)
				ft_print_two_char_numbers(x, n);
			n++;
		}
		x++;
	}
}
