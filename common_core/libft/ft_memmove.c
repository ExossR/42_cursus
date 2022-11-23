/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:37:12 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/09 19:06:25 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*source;

	dst = dest;
	source = src;
	while (n > 0)
	{
		n--;
		dst[n] = source[n];
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst > src)
		dst = ft_memrcpy(dst, src, n);
	else
		dst = ft_memcpy(dst, src, n);
	return (dst);
}
