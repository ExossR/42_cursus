/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:46:31 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/29 11:12:04 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (dest[i])
		i++;
	while (src[y])
	{
		dest[i] = src[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_size_malloc(int size, char **strs, char *sep)
{
	int	i;
	int	size_m;

	i = 0;
	size_m = 0;
	while (i < size)
	{
		size_m += ft_strlen(strs[i]);
		if (i != (size - 1))
			size_m += ft_strlen(sep);
		i++;
	}
	return (size_m);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		size_malloc;
	char	*res;

	if (size == 0)
	{
		res = malloc(sizeof(char));
		res[0] = '\0';
	}
	else
	{
		size_malloc = ft_size_malloc(size, strs, sep);
		res = malloc((size_malloc + 1) * sizeof(char));
		i = 0;
		res[0] = '\0';
		while (i < size)
		{
			res = ft_strcat(res, strs[i]);
			if (i != (size - 1))
				res = ft_strcat(res, sep);
			i++;
		}
		res[ft_strlen(res)] = '\0';
	}
	return (res);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	char *sep;
	char *res;
	//(void) argc;
	//(void) argv;

	sep = "|ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff|";
	res = ft_strjoin(argc, argv, sep);
	free(res);
	printf("%s", res);
	return (0);
}*/
