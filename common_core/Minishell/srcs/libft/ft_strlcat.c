/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:16:41 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/10 13:22:55 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	dstsize;
	unsigned int	i;

	i = 0;
	if (dst == 0 && size == 0)
		return (0);
	dstsize = ft_strlen(dst);
	if (size <= dstsize)
		return (size + ft_strlen(src));
	while (src[i] && dstsize + i < size - 1 && size > 0)
	{
		dst[dstsize + i] = src[i];
		i++;
	}
	if (size > 0)
		dst[dstsize + i] = '\0';
	return (dstsize + ft_strlen(src));
}
