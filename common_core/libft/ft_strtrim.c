/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:44:18 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/09 19:39:36 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_first(char const *str, char const *set)
{
	int	i;
	int	j;
	int	isin;

	i = 0;
	j = 0;
	isin = 1;
	while (str[i] != '\0' && isin == 1)
	{
		j = 0;
		isin = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
				isin = 1;
			j++;
		}
		i++;
	}
	return (i - 1);
}

static int	find_last(char const *str, char const *set)
{
	int	i;
	int	j;
	int	is_in;

	i = ft_strlen(str);
	is_in = 1;
	while (i >= 0 && is_in == 1)
	{
		is_in = 0;
		j = ft_strlen(set);
		while (j >= 0)
		{
			if (str[i] == set[j])
				is_in = 1;
			j--;
		}
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!s1)
		return (0);
	i = find_first(s1, set);
	j = find_last(s1, set);
	if (i > j)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof (char) * ((j - i) + 2));
	if (str == 0)
		return (0);
	k = 0;
	while (i <= j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
