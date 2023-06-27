/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:08:56 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/02 18:54:14 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(char *str)
{
	while (*str++)
		write(1, str - 1, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	char	result;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	result = (char)(n % 10) + '0';
	ft_putchar(result);
}

int	count_line(char *path)
{
	int		count;
	char	letter;
	int		file;

	count = 0;
	file = open(path, O_RDONLY);
	while (read(file, &letter, 1) != 0)
		if (letter == '\n')
			count++;
	close (file);
	return (count);
}
