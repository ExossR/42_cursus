/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:03:02 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/01 14:30:10 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	verif_charset(int pos, char *str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] != str[pos])
			return (0);
		i++;
		pos++;
	}
	return (1);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	nb_word;

	i = 0;
	nb_word = 0;
	if (!verif_charset(i, str, charset))
		nb_word++;
	i++;
	while (str[i])
	{
		if (!verif_charset(i, str, charset)
			&& verif_charset(i - ft_strlen(charset), str, charset)
			&& i >= ft_strlen(charset)
			&& ft_strlen(str) >= i + ft_strlen(charset))
			nb_word++;
		i++;
	}
	return (nb_word);
}

int	size_word(int pos, char *str, char *charset)
{
	int	i;

	i = 0;
	while (!verif_charset(pos, str, charset))
	{
		i++;
		pos++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	**longstr;

	i = 0;
	j = 0;
	size = count_word(str, charset);
	longstr = malloc((size + 1) * sizeof(char *));
	while (i < ft_strlen(str))
	{
		k = 0;
		if (!verif_charset(i, str, charset))
		{
			size = size_word(i, str, charset);
			longstr[j] = malloc((size + 1) * sizeof(char));
			while (k < size && k + i < ft_strlen(str))
			{
				longstr[j][k] = str[k + i];
				k++;
			}
			longstr[j][k] = '\0';
			j++;
			i += size + 1;
		}
		i++;
	}
	longstr[j] = 0;
	return (longstr);
}

int	main(int argc, char **argv)
{
	char **str;
	int	i;

	i = 0;
	str = ft_split(argv[1], argv[2]);
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}
