/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:57:20 by asahonet          #+#    #+#             */
/*   Updated: 2023/03/02 17:05:21 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	thread_create(t_philo *p, pthread_t *th, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i % 2 == 0 && pthread_create(&th[i], NULL, (void *)execs_p,
				&p[i]) != 0)
			printf("Philosopher %d failed to create.\n", i);
		if (i % 2 == 0 && pthread_detach(th[i]) != 0)
			printf("Philosopher %d failed to detached.\n", i);
		i++;
	}
	i = 0;
	usleep(100);
	while (i < n)
	{
		if (i % 2 != 0 && pthread_create(&th[i], NULL, (void *)execs_p,
				&p[i]) != 0)
			printf("Philosopher %d failed to create.\n", i);
		if (i % 2 != 0 && pthread_detach(th[i]) != 0)
			printf("Philosopher %d failed to detached.\n", i);
		i++;
	}
}

int	verif_dead(t_philo *p)
{
	pthread_mutex_lock(&p->inf_gen->dead);
	if (get_time_millisec() - p->last_eat >= p->inf_gen->time_die
		|| p->inf_gen->one_died == 1)
	{
		pthread_mutex_unlock(&p->inf_gen->dead);
		return (1);
	}
	pthread_mutex_unlock(&p->inf_gen->dead);
	return (0);
}

int	verif_eat(t_philo *p)
{
	pthread_mutex_lock(&p->inf_gen->nbeat);
	if ((p->inf_gen->nb_times_philo_eats != -1
			&& p->nbeats >= p->inf_gen->nb_times_philo_eats))
	{
		pthread_mutex_unlock(&p->inf_gen->nbeat);
		return (1);
	}
	pthread_mutex_unlock(&p->inf_gen->nbeat);
	return (0);
}

int	assign_nbeats(t_philo *p)
{
	int	n;

	n = 0;
	pthread_mutex_lock(&p->inf_gen->nbeat);
	n = p->inf_gen->nb_times_philo_eats;
	pthread_mutex_unlock(&p->inf_gen->nbeat);
	return (n);
}

long long	assign_timeset(t_philo *p)
{
	long long	time;

	time = 0;
	pthread_mutex_lock(&p->inf_gen->prep);
	time = p->inf_gen->timeset;
	pthread_mutex_unlock(&p->inf_gen->prep);
	return (time);
}
