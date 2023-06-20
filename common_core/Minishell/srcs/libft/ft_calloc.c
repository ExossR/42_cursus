/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:40:35 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/10 16:55:43 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_bzero(void *s, unsigned int n);

void	*ft_calloc(unsigned int element_count, unsigned int element_size)
{
	int		i;
	void	*output;

	if (element_count == 4294967295 || element_size == 4294967295)
		return (0);
	i = 0;
	output = malloc(element_count * element_size);
	if (output == 0)
		return (0);
	ft_bzero(output, element_count * element_size);
	return (output);
}

static void	ft_bzero(void *s, unsigned int n)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)s;
	if (n > 0)
	{
		while (n > 0)
		{
			temp[i++] = 0;
			n--;
		}
	}
}
