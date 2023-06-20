/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:28:17 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/11 11:54:06 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*substr_mainpart(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		if (i == start)
		{
			while ((i - start) < len)
			{
				str[i - start] = s[i];
				i++;
			}
			break ;
		}
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char	*str;

	if (start > ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (0);
		str[0] = '\0';
	}
	else
		str = substr_mainpart(s, start, len);
	return (str);
}
