/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:24:02 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/05 12:41:24 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			j++;
		i++;
	}
	return (j);
}
