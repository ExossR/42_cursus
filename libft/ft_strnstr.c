/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:41:52 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/07 14:16:36 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	if (!haystack && !n)
		return (0);
	i = 0;
	j = 0;
	while (haystack[i] && i < n)
	{
		j = 0;
		while (haystack[i + j] && haystack[i + j] == needle[j] && i + j < n)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
