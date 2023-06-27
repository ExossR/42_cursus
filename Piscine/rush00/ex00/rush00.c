/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:08:45 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/17 14:49:20 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_inter(int abs)
{
	int	cpt;

	cpt = 1;
	while (cpt <= abs)
	{
		if (cpt == 1 || cpt == abs)
			ft_putchar('|');
		else
			ft_putchar(' ');
		cpt++;
	}
}

void	ft_limit(int abs)
{
	int	cpt;

	cpt = 1;
	while (cpt <= abs)
	{
		if (cpt == 1 || cpt == abs)
			ft_putchar('o');
		else
			ft_putchar('-');
		cpt++;
	}
}

void	rush(int abs, int ord)
{
	int	ord_max;

	ord_max = ord;
	while (ord > 0 && abs > 0)
	{
		if (ord == ord_max || ord == 1)
			ft_limit(abs);
		else
			ft_inter(abs);
		ft_putchar('\n');
		ord--;
	}
}
