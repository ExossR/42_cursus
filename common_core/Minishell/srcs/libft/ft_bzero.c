/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:39:42 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/17 11:20:06 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, unsigned int n)
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
