/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 09:58:05 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/25 10:12:36 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	int	n_arg;

	n_arg = argc - 1;
	while (n_arg > 0)
	{
		write(1, argv[n_arg], ft_strlen(argv[n_arg]));
		write(1, "\n", 1);
		n_arg--;
	}
	return (0);
}
