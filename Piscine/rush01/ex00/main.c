/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:50:31 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/25 22:28:22 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tower.h"

void	ft_add_struct(int pos, char *str, t_valeur *tab)
{
	if (pos < 8)
		tab->up[(pos / 2) % 4] = str[pos] - 48;
	else if (pos < 16)
		tab->down[(pos / 2) % 4] = str[pos] - 48;
	else if (pos < 24)
		tab->left[(pos / 2) % 4] = str[pos] - 48;
	else
		tab->right[(pos / 2) % 4] = str[pos] - 48;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	check_args(int argc, char **argv, t_valeur *tab)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(argv[1]);
	if (argc != 2 || size != 31)
		return (1);
	while (i < size)
	{
		if (i % 2 == 0)
		{
			if (argv[1][i] > '4' || argv[1][i] < '1')
				return (1);
			else
				ft_add_struct(i, argv[1], tab);
		}
		if (i % 2 == 1)
		{
			if (argv[1][i] != ' ')
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_valeur	coeffs;
	int			tab[4][24][4];
	int			***valid;

	if (check_args(argc, argv, &coeffs) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_tries(tab[0]);
	init_tries(tab[1]);
	init_tries(tab[2]);
	init_tries(tab[3]);
	valid = 0;
	valid = initialize(tab, valid, coeffs);
	if (valid == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	solve_map(valid, coeffs);
	return (0);
}
