/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:42:12 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/25 22:27:19 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cond_try(int a, int b, int c, int d)
{
	if (a != b && b != c && a != c && a != d
		&& b != d && d != c)
		return (1);
	return (0);
}

int	init_tries2(int tab[24][4], int i, int a, int b)
{
	int	c;
	int	d;
	int	total;

	c = 1;
	total = 0;
	while (c < 5)
	{
		d = 1;
		while (d < 5)
		{
			if (cond_try(a, b, c, d))
			{
				tab[i + total][0] = a;
				tab[i + total][1] = b;
				tab[i + total][2] = c;
				tab[i + total][3] = d;
				total++;
			}
			d++;
		}
		c++;
	}
	return (total);
}

void	init_tries(int tab[24][4])
{
	int	a;
	int	b;
	int	i;

	i = 0;
	a = 1;
	while (a < 5)
	{
		b = 1;
		while (b < 5)
		{
			i += init_tries2(tab, i, a, b);
			b++;
		}
		a++;
	}
}
