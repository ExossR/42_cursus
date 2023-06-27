/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 07:49:36 by lfresnay          #+#    #+#             */
/*   Updated: 2022/10/02 22:49:02 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	size;
	int	i;

	size = ft_strlen(src);
	i = 0;
	while (i < size)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		size;

	size = ft_strlen(src) + 1;
	copy = (char *)(malloc(size * sizeof(char)));
	copy = ft_strcpy(copy, src);
	return (copy);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	size;
	int	i;

	size = ft_strlen(s1);
	i = 0;
	while (i <= size)
	{
		if (*(s1 + i) > *(s2 + i))
			return (1);
		else if (*(s1 + i) < *(s2 + i))
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	sizesrc;
	int	sizedest;

	i = 0;
	sizesrc = ft_strlen(src);
	sizedest = ft_strlen(dest);
	while (i <= sizesrc)
	{
		*(dest + sizedest + i) = *(src + i);
		i++;
	}
	return (dest);
}
