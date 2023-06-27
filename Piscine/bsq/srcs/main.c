/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeyre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:49:52 by aribeyre          #+#    #+#             */
/*   Updated: 2022/10/06 01:45:28 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int		i;
	char	cc[20];

	if (argc == 1)
	{
		i = read(0, cc, 20);
		cc[5] = '\0';
		if (ft_verif_parsing(cc, 0) == 0 || solve_puzzle(cc) == 0)
			write(1, "map error\n", 10);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (ft_verif_parsing(argv[i], 0) == 0 || solve_puzzle(argv[i]) == 0)
			write(1, "map error\n", 10);
		i++;
		if (i < argc)
			write(1, "\n", 1);
	}	
	return (0);
}
