/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:35:03 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/02 19:00:26 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*add_val_tabfirst(int nb_elements, char *result, char *str)
{
	int	i;

	i = -1;
	if (nb_elements == 0)
	{
		while (++i < 3)
			result[i] = str[i];
	}
	else if (nb_elements == 1)
	{
		i++;
		result[i + 2] = str[i];
		i++;
	}
	else if (nb_elements == 2)
	{
		while (++i < 2)
			result[i + 1] = str[i];
	}
	result[i + nb_elements + 1] = '\0';
	return (result);
}

char	**split_number(char *str, int i, int j)
{
	int		size;
	char	**res;

	size = ft_strlen(str) / 3;
	if (ft_strlen(str) % 3 != 0)
		size++;
	res = malloc((size + 1) * sizeof(char *));
	while (++i < size)
	{
		res[i] = malloc(4 * sizeof(char *));
		res[i] = init_tab_zero(res[i]);
		if (i == 0)
		{
			res[i] = add_val_tabfirst(ft_strlen(str) % 3, res[i], str);
			j += ft_mod(ft_strlen(str) % 3);
		}
		else
		{
			res[i] = add_val_tabrest(res[i], str, j);
			j += 3;
		}
	}
	res[i] = 0;
	return (res);
}

int	check_unsignedint(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i > 10)
		return (0);
	if (!ft_atoi_check_unsignedint(str))
		return (0);
	return (1);
}

int	verif_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (!check_unsignedint(str))
		return (0);
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	nb_param;
	int	op_dict;

	nb_param = 0;
	op_dict = 0;
	if (argc == 1 || argc > 3)
		return (0);
	else if (argc == 2)
		return (verif_num(argv[1]));
	else
	{
		op_dict = open(argv[1], O_RDONLY);
		nb_param = verif_num(argv[2]);
		if (op_dict == -1 || nb_param == 0)
			return (0);
		return (2);
	}
}
