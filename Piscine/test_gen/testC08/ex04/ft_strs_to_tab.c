/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:22:36 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/30 10:35:07 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			size;
	t_stock_str	*stock;

	stock = malloc(ac * sizeof(t_stock_str));
	i = 0;
	while (i < ac)
	{
		size = ft_strlen(av[i]);
		stock[i].size = size;
		stock[i].str = malloc(size * sizeof(char));
		stock[i].str = av[i];
		stock[i].copy = malloc(size * sizeof(char));
		stock[i].copy = ft_strcpy(stock[i].copy, stock[i].str);
		if (stock[i].str == 0 || stock[i].copy == 0)
			return (0);
		i++;
	}
	stock[i].str = 0;
	return (stock);
}

/*int	main(int argc, char **argv)
{
	int	i;
	t_stock_str *stock;

	i = 0;
	stock = ft_strs_to_tab(argc, argv);
	ft_show_tab(stock);
	return (0);
}*/
