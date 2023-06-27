/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:48:34 by ehouot            #+#    #+#             */
/*   Updated: 2022/09/17 16:52:34 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_intern(int abs)
{
	int	cpt;

	cpt = 1;
	while (cpt <= abs)
	{
		if (cpt == 1 || cpt == abs)
			ft_putchar('B');
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
		if (cpt == 1)
			ft_putchar('A');
		else if (cpt == abs)
			ft_putchar('C');
		else
			ft_putchar('B');
		cpt++;
	}
}

void	rush(int abs, int ord)
{
	int	ordmax;

	ordmax = ord;
	while (ord > 0 && abs > 0)
	{
		if (ord == ordmax || ord == 1)
			ft_limit(abs);
		else
			ft_intern(abs);
		ft_putchar('\n');
		ord--;
	}
}
