/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:29:58 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/18 16:45:54 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	rush(int abs, int ord);

int ft_puissance(int n, int p)
{
	while (p != 0)
	{
		n = n * 10;
		p--;
	}
	return (n);
}

int	ft_int_param(char *str)
{
	int	i;
	int	n;
	int	convert;
	int	nb;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
			n++;
		else if (n > 0 && (str[i] < 48 || str[i] > 57))
			break;
		i++;
	}
	i = 0;
	while(str[i])
	{
		if (str[i] > 47 && str[i] < 58)
		{
			convert = str[i] - '0';
			if (n - 1 > 1)
				nb += ft_puissance(convert, n - 1);
			else
				nb += convert;
			n--;
		}
		else if (n == 0 && (str[i] < 48 || str[i] > 57))
			break;
		i++;
	}
	return (nb);
}

int	main(int argc, char *argv[])
{
	int	nb1;
	int	nb2;

	if (argc == 3)
	{
		nb1 = ft_int_param(argv[1]);
		nb2 = ft_int_param(argv[2]);
		write(1, &nb1, 1);
		write(1, " ", 1);
		write(1, &nb2, 1);
		//rush(nb1, nb2);
	}
	return (0);
}
