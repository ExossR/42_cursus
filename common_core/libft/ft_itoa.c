/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:33:05 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/07 15:15:32 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_nb(int n)
{
	int	i;

	i = 1;
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

static char	*number_to_char(char *str, long n)
{
	int		i;
	long	limit;
	long	temp;

	i = 0;
	limit = 10;
	if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	while (limit <= n)
	{
		temp = n;
		while (temp >= limit)
			temp /= 10;
		str[i++] = temp % 10 + '0';
		limit *= 10;
	}
	str[i++] = n % 10 + '0';
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = malloc((size_nb(n) + 1) * sizeof(char));
	if (!str)
		return (0);
	str = number_to_char(str, (long) n);
	return (str);
}
