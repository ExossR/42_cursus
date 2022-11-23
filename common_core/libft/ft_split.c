/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:39:01 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/09 19:24:02 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*ft_strndup(const char *s, size_t size)
{
	size_t	i;
	char	*str;

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

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	if (!s)
		return (0);
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
			str[j++] = ft_strndup(s + k, i - k);
	}
	str[j] = 0;
	return (str);
}
