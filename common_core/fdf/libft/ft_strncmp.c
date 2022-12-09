/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:43:41 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/09 19:07:34 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *)s1;
	s = (unsigned char *)s2;
	i = 0;
	while ((f[i] || s[i]) && i < n)
	{
		if (f[i] != s[i])
			return (f[i] - s[i]);
		i++;
	}
	return (0);
}
