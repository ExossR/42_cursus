/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:44:12 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/07 14:31:58 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (int)ft_strlen(s);
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (i > -1)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
