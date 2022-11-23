/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:37:01 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/09 19:05:19 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	char		*source;

	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	dst = (char *)dest;
	source = (char *)src;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dst);
}
