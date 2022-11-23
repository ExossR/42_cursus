/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:21:10 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/18 17:13:57 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_put_argid(int n)
{
	int	i;

	i = 1;
	ft_putnbr_fd(n, 1);
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	size_put_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}

int	size_put_adr(unsigned long long adr)
{
	int		i;
	char	*base;

	base = "0123456789abcdef";
	if (adr > 15)
	{
		size_put_adr(adr / 16);
		write(1, &base[adr % 16], 1);
	}
	else
	{
		write(1, "0x", 2);
		write(1, &base[adr % 16], 1);
	}
	i = 0;
	if (adr == 0)
		i = 1;
	while (adr != 0)
	{
		adr /= 16;
		i++;
	}
	return (i + 2);
}

void	ft_putunsnbr_fd(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		ft_putunsnbr_fd(n / 10, fd);
		i = n % 10 + 48;
		write(fd, &i, 1);
	}
	else
	{
		n += 48;
		write(fd, &n, 1);
	}
}

int	size_put_unsi(unsigned int n)
{
	int	i;

	i = 0;
	ft_putunsnbr_fd(n, 1);
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
