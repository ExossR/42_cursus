/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:26:53 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/10 13:32:23 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *s);

static int	find_i(char const *str, char const *set);

static int	find_j(char const *str, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	int		i;
	int		j;
	int		k;

	i = find_i(s1, set);
	j = find_j(s1, set);
	if (i > j)
	{
		output = malloc(sizeof (char) * 1);
		output[0] = '\0';
		return (output);
	}
	output = malloc(sizeof (char) * ((j - i) + 2));
	if (output == 0)
		return (0);
	k = 0;
	while (i <= j)
	{
		output[k] = s1[i];
		k++;
		i++;
	}	
	output[k] = '\0';
	return (output);
}

static int	find_i(char const *str, char const *set)
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

static int	find_j(char const *str, char const *set)
{
	int	i;
	int	j;
	int	isin;

	i = ft_strlen(str);
	isin = 1;
	while (i >= 0 && isin == 1)
	{
		isin = 0;
		j = ft_strlen(set);
		while (j >= 0)
		{
			if (str[i] == set[j])
				isin = 1;
			j--;
		}
		i--;
	}
	return (i + 1);
}

static int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
