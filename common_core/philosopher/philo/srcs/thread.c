/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:59:11 by asahonet          #+#    #+#             */
/*   Updated: 2023/03/02 17:06:05 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*execs_p(void *ph)
{
	int			i;
	int			n;
	t_philo		*p;
	long long	time;

	p = (t_philo *) ph;
	i = 0;
	n = assign_nbeats(p);
	time = assign_timeset(p);
	if (n == -1)
		i = -2;
	while (i < n)
	{
		if (verif_dead(p) == 1)
			break ;
		is_eating(p, time);
		if (verif_eat(p) == 1)
			break ;
		is_sleeping(p, time);
		is_thinking(p, time);
		if (n != -1)
			i++;
	}
	return (0);
}

int	watch_death(t_gen_philo *ginf, long long last_eat, int i)
{
	pthread_mutex_lock(&ginf->dead);
	if (get_time_millisec() - last_eat >= ginf->time_die)
	{
		ginf->one_died = 1;
		printf("%lld %d died\n", get_time_millisec() - ginf->timeset, i);
		pthread_mutex_unlock(&ginf->dead);
		return (1);
	}
	pthread_mutex_unlock(&ginf->dead);
	return (0);
}

int	watcher(t_philo *p, t_gen_philo *ginf)
{
	long long	last_eat;
	int			i;
	int			n;
	int			nb_philo;

	i = 0;
	n = 0;
	last_eat = 0;
	pthread_mutex_lock(&ginf->philo);
	nb_philo = ginf->nb_philo;
	pthread_mutex_unlock(&ginf->philo);
	while (n != nb_philo)
	{
		pthread_mutex_lock(&ginf->nbeat);
		if (p[i].inf_gen->nb_times_philo_eats != -1
			&& p[i].nbeats >= p[i].inf_gen->nb_times_philo_eats)
			n++;
		pthread_mutex_unlock(&ginf->nbeat);
		if (watch_death(ginf, p[i].last_eat, i) == 1)
			break ;
		i = (i + 1) % nb_philo;
		usleep(500);
	}
	usleep(250000);
	return (0);
}

int	init_thread(t_philo **p, t_gen_philo *ginf)
{
	pthread_t	*th;

	th = malloc(ginf->nb_philo * sizeof(pthread_t));
	if (!th)
		return (1);
	ginf->timeset = get_time_millisec();
	thread_create(*p, th, ginf->nb_philo);
	watcher(*p, ginf);
	free(th);
	return (0);
}
