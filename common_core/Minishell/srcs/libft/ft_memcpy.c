/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:51:13 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/10 10:40:23 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	char		*temp;
	const char	*temp_src;
	int			i;

	i = 0;
	temp_src = src;
	temp = dest;
	if (temp_src == 0 && temp == 0)
		return (0);
	if (n > 0)
	{
		while (n != 0)
		{
			temp[i] = temp_src[i];
			i++;
			n--;
		}
	}
	return (temp);
}
