/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:38:59 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/17 18:57:19 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	ft_inter(int abs)
{
	int	cpt;

	cpt = 1;
	while (cpt <= abs)
	{
		if (cpt == 1 || cpt == abs)
			ft_putchar('*');
		else
			ft_putchar(' ');
		cpt++;
	}
}

void	ft_limit(int abs, int first_line)
{
	int	cpt;

	cpt = 1;
	while (cpt <= abs)
	{
		if (cpt == 1)
		{
			if (first_line == 1)
				ft_putchar('/');
			else
				ft_putchar('\\');
		}
		else if (cpt == abs)
		{
			if (first_line == 1)
				ft_putchar('\\');
			else
				ft_putchar('/');
		}
		else
			ft_putchar('*');
		cpt++;
	}
}

void	rush(int abs, int ord)
{
	int	ord_max;
	int	first_line;

	ord_max = ord;
	while (ord > 0 && abs > 0)
	{
		if (ord == ord_max)
		{
			first_line = 1;
			ft_limit(abs, first_line);
		}
		else if (ord == 1)
		{
			first_line = 0;
			ft_limit(abs, first_line);
		}
		else
			ft_inter(abs);
		ft_putchar('\n');
		ord--;
	}
}
