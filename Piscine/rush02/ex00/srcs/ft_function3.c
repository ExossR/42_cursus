/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:35:53 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/02 18:54:38 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*put_in_chain(char letter, char *buf)
{
	buf[0] = letter;
	buf[1] = '\0';
	return (buf);
}

char	*put_in_chain_tenth(char letter, char *buf)
{
	buf[0] = letter;
	buf[1] = '0';
	buf[2] = '\0';
	return (buf);
}

void	print_power(int i, t_number **tab)
{
	char	*buf;
	int		j;

	buf = malloc (((i * 3) + 1) * sizeof(char));
	buf[0] = '1';
	j = 1;
	while (i > 1)
	{
		buf[j] = '0';
		buf[j + 1] = '0';
		buf[j + 2] = '0';
		j += 3;
		i--;
	}
	buf[j] = '\0';
	ft_putstr(find_trad(buf, tab));
	free(buf);
}

int	find_number_tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}
