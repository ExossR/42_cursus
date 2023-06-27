/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:40:16 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/02 20:34:52 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	char		**str;
	t_number	**dict;

	if (check_args(argc, argv) == 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (argc == 2)
	{
		dict = malloc(count_line("numbers.dict") * sizeof(t_number *));
		str = split_number(argv[1], -1, 0);
		creating_array(dict, "numbers.dict");
	}
	if (argc == 3)
	{
		dict = malloc(count_line(argv[1]) * sizeof(t_number *));
		str = split_number(argv[2], -1, 0);
		creating_array(dict, argv[1]);
	}
	print_all_number(str, dict);
	ft_putstr("\n");
	return (0);
}
