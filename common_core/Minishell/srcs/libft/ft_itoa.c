/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:47:07 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/10 13:40:06 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int			count_number(long long n);

static long long	if_negative(long long n, char *output, int *i);

static char			*grab_line_end(char *output, int i, long long n);

static void			grab_line_start(long long *limits, int *i);

char	*ft_itoa(int n)
{
	char		*output;
	long long	limits;
	long long	temp;
	int			i;
	long long	new_n;

	new_n = (long long) n;
	grab_line_start(&limits, &i);
	output = malloc(sizeof(char) * (count_number(new_n) + 1));
	if (output == 0)
		return (0);
	new_n = if_negative(new_n, output, &i);
	while (limits <= new_n)
	{
		temp = new_n;
		while (temp >= limits)
			temp = temp / 10;
		output[i++] = (temp % 10) + '0';
		limits = limits * 10;
	}
	output = grab_line_end(output, i, new_n);
	return (output);
}

static void	grab_line_start(long long *limits, int *i)
{
	*limits = 10;
	*i = 0;
}

static char	*grab_line_end(char *output, int i, long long n)
{
	output[i++] = n % 10 + '0';
	output[i] = '\0';
	return (output);
}

static long long	if_negative(long long n, char *output, int *i)
{
	if (n < 0)
	{
		n = -1 * n;
		output[*i] = '-';
		*i = *i + 1;
	}
	return (n);
}

static int	count_number(long long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n < 10)
		return (i);
	else
	{
		while (n >= 10)
		{
			n = n / 10;
			i++;
		}
		return (i);
	}
}
