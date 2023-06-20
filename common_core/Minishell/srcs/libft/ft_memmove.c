/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:51:55 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/10 10:43:15 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	*ft_memcpy(void *dest, const void *src, unsigned int n);

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	char				*temp_dest;
	const char			*temp_src;

	temp_dest = (char *) dest;
	temp_src = (char *) src;
	if (temp_dest == 0 && temp_src == 0)
		return (0);
	if (temp_dest > temp_src)
	{
		while (n > 0)
		{
			n--;
			temp_dest[n] = temp_src[n];
		}
	}
	else
		temp_dest = ft_memcpy(dest, src, n);
	return (temp_dest);
}

static void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	char		*temp;
	const char	*temp_src;
	int			i;

	i = 0;
	temp_src = src;
	temp = dest;
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
