/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:32:43 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/26 14:36:46 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	usleep_debug(int time_to)
{
	long long	tmp;

	tmp = get_time_millisec();
	while (tmp + time_to > get_time_millisec())
		usleep(200);
}

long long	get_time_millisec(void)
{
	long long		time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

int	verif_vals(char **argv)
{
	int	i;

	i = 1;
	if (ft_atoi(argv[1]) == 0)
		return (1);
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}

int	parsing_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] > 47 && argv[i][j] < 58))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
