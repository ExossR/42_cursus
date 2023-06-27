/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:23:32 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/15 12:14:00 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_three_int(int i1, int i2, int i3)
{
	i1 += 48;
	i2 += 48;
	i3 += 48;
	write(1, &i1, 1);
	write(1, &i2, 1);
	write(1, &i3, 1);
	if (i1 < 55)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	x;
	int	c;
	int	d;
	int	u;

	x = 0;
	while (x <= 999)
	{
		c = x / 100;
		d = x / 10 % 10;
		u = x % 10;
		if (c < d && d < u && c < u)
			ft_print_three_int(c, d, u);
		x++;
	}
}

int main(void)
{
	ft_print_comb();
}
