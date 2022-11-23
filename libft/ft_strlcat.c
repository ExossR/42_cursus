/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:40:59 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/07 14:23:44 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;

	if (dst == 0 && size == 0)
		return (0);
	i = 0;
	dst_size = ft_strlen(dst);
	if (size <= dst_size)
		return (size + ft_strlen(src));
	while (src[i] && dst_size + i < size - 1 && size > 0)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	if (size > 0)
		dst[dst_size + i] = '\0';
	if (size <= dst_size)
		return (size + ft_strlen(src));
	return (dst_size + ft_strlen(src));
}
