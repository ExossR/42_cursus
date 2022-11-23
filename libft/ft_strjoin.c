/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:39:53 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/07 14:26:04 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		n;
	char	*cat;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (0);
	cat = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cat)
		return (0);
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	cat[i] = '\0';
	while (s2[n])
	{
		cat[i + n] = s2[n];
		n++;
	}
	cat[i + n] = '\0';
	return (cat);
}
