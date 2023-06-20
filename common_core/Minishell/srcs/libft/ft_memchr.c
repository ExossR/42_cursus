/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:49:32 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/10 10:45:10 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *memory, int searchedChar, unsigned int size)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *) memory;
	while ((unsigned int) i < size)
	{
		if (*temp == (char) searchedChar)
			return (temp);
		temp++;
		i++;
	}
	return (0);
}
