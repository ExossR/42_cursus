/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:02:38 by jbranche          #+#    #+#             */
/*   Updated: 2023/01/18 19:33:21 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *s)
{	
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	is_charset(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	number_of_word(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] && is_charset(s[i], c))
			i++;
		if (s[i] && !is_charset(s[i], c))
			nb++;
		while (s[i] && !is_charset(s[i], c))
			i++;
	}
	return (nb);
}

char	*ft_strndup(char *s, unsigned int size)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[i] = '\0';
	while (s[i] && i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	str = malloc((number_of_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_charset(s[i], c))
			i++;
		k = i;
		while (s[i] && !is_charset(s[i], c))
			i++;
		if (k != i)
		{
			str[j] = ft_strndup(s + k, i - k);
			j++;
		}
	}
	str[j] = 0;
	return (str);
}
