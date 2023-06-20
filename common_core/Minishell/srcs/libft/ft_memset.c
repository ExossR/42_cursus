/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:52:51 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/08 16:48:19 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *pointer, int value, unsigned int count)
{
	char	*temp;

	temp = pointer;
	if (count > 0)
	{
		while (count > 0)
		{
			*temp = value;
			temp++;
			count--;
		}
	}
	return (pointer);
}
