/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:50:04 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/10 10:45:47 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *first, const void *second, unsigned int n)
{
	unsigned int			i;
	unsigned char			*tempf;
	unsigned char			*temps;

	if (first == 0 && second == 0)
		return (0);
	tempf = (unsigned char *) first;
	temps = (unsigned char *) second;
	i = 0;
	while (i < n)
	{
		if (tempf[i] != temps[i])
			return (tempf[i] - temps[i]);
		i++;
	}
	return (0);
}
