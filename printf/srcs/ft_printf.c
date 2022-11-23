/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:13:19 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/19 12:19:55 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_put_hexamin(unsigned int x)
{
	int		i;
	char	*base;

	base = "0123456789abcdef";
	if (x > 15)
	{
		size_put_hexamin(x / 16);
		write(1, &base[x % 16], 1);
	}
	else
		write(1, &base[x % 16], 1);
	i = 0;
	if (x == 0)
		i = 1;
	while (x != 0)
	{
		x /= 16;
		i++;
	}
	return (i);
}

int	size_put_hexamaj(unsigned int x)
{
	int		i;
	char	*base;

	base = "0123456789ABCDEF";
	if (x > 15)
	{
		size_put_hexamaj(x / 16);
		write(1, &base[x % 16], 1);
	}
	else
		write(1, &base[x % 16], 1);
	i = 0;
	if (x == 0)
		i = 1;
	while (x != 0)
	{
		x /= 16;
		i++;
	}
	return (i);
}

int	put_value(va_list list, char c)
{
	if (c == 'i' || c == 'd')
		return (size_put_argid(va_arg(list, int)));
	else if (c == 'c')
		return (ft_putchar_fd(va_arg(list, int), 1));
	else if (c == 's')
		return (size_put_str(va_arg(list, char *)));
	else if (c == 'p')
		return (size_put_adr(va_arg(list, unsigned long long)));
	else if (c == 'x')
		return (size_put_hexamin(va_arg(list, unsigned int)));
	else if (c == 'X')
		return (size_put_hexamaj(va_arg(list, unsigned int)));
	else if (c == 'u')
		return (size_put_unsi(va_arg(list, unsigned int)));
	else
	{
		write(1, &c, 1);
		return (1);
	}
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	size_str;
	va_list	list;

	va_start(list, str);
	i = 0;
	size_str = 0;
	while (str[i])
	{
		if (str[i] != '%')
			size_str += ft_putchar_fd(str[i], 1);
		else
		{
			i++;
			if (str[i] != '\0')
				size_str += put_value(list, str[i]);
			else
				size_str++;
		}
		i++;
	}
	va_end(list);
	return (size_str);
}
