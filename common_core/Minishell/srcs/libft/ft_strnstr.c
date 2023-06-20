/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:31 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/10 11:27:36 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (*little == '\0')
		return ((char *) big);
	if (!big && !n)
		return (0);
	while (big[i] != 0 && i < n)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && i + j < n)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
