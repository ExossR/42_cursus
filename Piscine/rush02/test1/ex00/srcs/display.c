/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:54:53 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/02 18:46:28 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	print_part1(char *trio, t_number **tab, int size_condition[2])
{
	if (trio[2] == '0')
		return (0);
	ft_putstr(find_trad(&trio[2], tab) + size_condition[1]);
	size_condition[1] = 0;
	return (0);
}

int	print_part2(char *trio, t_number **tab, int size_condition[2])
{
	ft_putstr(find_trad(&trio[1], tab) + size_condition[1]);
	size_condition[1] = 0;
	return (0);
}

int	print_part3(char *trio, t_number **tab, char *buf, int size_condition[2])
{
	int	i;

	if (trio[2] == '0')
	{
		if (trio[1] == '0')
			return (0);
		ft_putstr(find_trad(&trio[1], tab) + size_condition[1]);
		size_condition[1] = 0;
	}
	else
	{
		i = size_condition[1];
		ft_putstr(find_trad(put_in_chain_tenth(trio[1], buf), tab) + i);
		ft_putstr(find_trad(put_in_chain(trio[2], buf), tab));
		size_condition[1] = 0;
	}
	return (0);
}

int	print_3_number(char *trio, t_number **tab, char *buf, int size_condition[2])
{
	int	i;

	if (ft_strcmp("000", trio) == 0 && size_condition[0] == 1)
		ft_putstr(find_trad("0", tab) + 1);
	if (ft_strcmp("000", trio) == 0)
		return (0);
	if (trio[0] > '0')
	{
		i = size_condition[1];
		ft_putstr(find_trad(put_in_chain(trio[0], buf), tab) + i);
		ft_putstr(find_trad("100", tab));
		size_condition[1] = 0;
	}
	if (trio[1] == '0')
		print_part1(trio, tab, size_condition);
	else if (trio[1] < '2')
		print_part2(trio, tab, size_condition);
	else
		print_part3(trio, tab, buf, size_condition);
	return (0);
}

void	print_all_number(char **tab, t_number **dict)
{
	int		i;
	char	*buf;
	int		size_condition[2];

	buf = malloc(sizeof(char) * 2);
	i = 0;
	size_condition[0] = find_number_tab_size(tab);
	size_condition[1] = 1;
	while (i < size_condition[0])
	{
		print_3_number(tab[i], dict, buf, size_condition);
		if ((size_condition[0] - i) > 1)
			print_power((size_condition[0] - i), dict);
		i++;
	}
	free(buf);
}
