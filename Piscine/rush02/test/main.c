/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:24:45 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/02 18:09:14 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*init_tab_zero(char *str)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

char	*add_val_tabrest(char *result, char *str, int key)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		result[i] = str[key + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_mod(int mod)
{
	if (mod == 0)
		return (3);
	else if (mod == 1)
		return (1);
	else
		return (2);
}

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

int	ft_atoi_check_unsignedint(char *str)
{
	unsigned int	i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		if (nb * 10 + (str[i] - 48) > 4294967295)
			return (0);
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (1);
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

int	main(int argc, char **argv)
{
	char	**str;
	int		i;
	int		check;

	i = 0;
	check = check_args(argc, argv);
	if (!check)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else if (check == 1)
	{
		str = split_number(argv[1], -1, 0);
		while (str[i])
		{
			printf("%s\n", str[i]);
			i++;
		}
	}
	else
		return (0);
}
