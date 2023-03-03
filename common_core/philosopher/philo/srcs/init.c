/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:10:33 by asahonet          #+#    #+#             */
/*   Updated: 2023/03/02 16:52:34 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_mutex(t_gen_philo **ginf)
{
	pthread_mutex_init(&(*ginf)->sleep_p, NULL);
	pthread_mutex_init(&(*ginf)->think_p, NULL);
	pthread_mutex_init(&(*ginf)->prep, NULL);
	pthread_mutex_init(&(*ginf)->dead, NULL);
	pthread_mutex_init(&(*ginf)->eat, NULL);
	pthread_mutex_init(&(*ginf)->nbeat, NULL);
	pthread_mutex_init(&(*ginf)->philo, NULL);
}

int	init_gen(t_gen_philo **ginf, int argc, char **argv)
{
	int				i;
	pthread_mutex_t	*mutex;

	i = 0;
	(*ginf)->nb_philo = ft_atoi(argv[1]);
	(*ginf)->time_die = ft_atoi(argv[2]);
	(*ginf)->time_eat = ft_atoi(argv[3]);
	(*ginf)->time_sleep = ft_atoi(argv[4]);
	if (argc == 6 && ft_atoi(argv[5]) > 0)
		(*ginf)->nb_times_philo_eats = ft_atoi(argv[5]);
	else
		(*ginf)->nb_times_philo_eats = -1;
	(*ginf)->timeset = get_time_millisec();
	(*ginf)->one_died = 0;
	mutex = malloc((*ginf)->nb_philo * sizeof(pthread_mutex_t));
	if (!mutex)
		return (1);
	while (i < (*ginf)->nb_philo)
		pthread_mutex_init(&mutex[i++], NULL);
	init_mutex(ginf);
	(*ginf)->mutex = mutex;
	return (0);
}

int	init_philo(t_philo **p, t_gen_philo *ginf)
{
	int				i;

	i = 0;
	while (i < ginf->nb_philo)
	{
		(*p)[i].nb_philo = ginf->nb_philo;
		(*p)[i].num_philo = i;
		(*p)[i].last_eat = get_time_millisec();
		(*p)[i].nbeats = 0;
		(*p)[i].inf_gen = ginf;
		i++;
	}
	return (0);
}

int	init_struct(t_philo **p, t_gen_philo **ginf, int argc, char **argv)
{
	(*ginf) = malloc(sizeof(t_gen_philo));
	if (!(*ginf))
		return (1);
	(*ginf)->mutex = 0;
	if (init_gen(ginf, argc, argv) == 1)
		return (1);
	(*p) = malloc((*ginf)->nb_philo * sizeof(t_philo));
	if (!(*p))
		return (1);
	return (init_philo(p, *ginf));
}
