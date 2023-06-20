/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:20:55 by jbranche          #+#    #+#             */
/*   Updated: 2022/12/06 16:45:40 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *first, const char *second, unsigned int length)
{
	unsigned int	i;
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *) first;
	s = (unsigned char *) second;
	i = 0;
	while ((f[i] != 0 || s[i] != 0) && i < length)
	{
		if (f[i] != s[i])
			return (f[i] - s[i]);
		i++;
	}
	return (0);
}
