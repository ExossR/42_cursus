/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 02:23:35 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/06 14:57:42 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		if (str[i] && !is_charset(str[i], charset))
			nb++;
		while (str[i] && !is_charset(str[i], charset))
			i++;
	}
	return (nb);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(n * sizeof(char));
	while (src[i] && i < n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		k;
	int		j;
	int		nb_word;
	char	**res;

	i = 0;
	k = 0;
	nb_word = count_word(str, charset);
	res = malloc((nb_word + 1) * sizeof(char *));
	while (k < nb_word)
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		j = i;
		while (str[i] && !is_charset(str[i], charset))
			i++;
		res[k] = ft_strndup(str + j, i - j);
		k++;
	}
	res[k] = 0;
	return (res);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int i = 0;
	char **str;

	str = ft_split(argv[1], argv[2]);
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}
